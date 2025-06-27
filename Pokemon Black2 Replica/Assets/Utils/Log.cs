using System;
using System.Collections;
using System.Linq;
using System.Linq.Expressions;
using System.Reflection;
using UnityEngine;

namespace Utils
{
    public static class Logger
    {
        public static void Log<T>(Expression<Func<T>> expression, string logMessage = "", int depth = 2)
        {
            string stackName = GetStack(expression.Body);
            object logObject = expression.Compile().Invoke();

            string logObjectInformation;
            logObjectInformation = FormatObjectInformation(logObject, 1, depth);
            string objectTypeAndParameters = GetObjectTypeAndParameters(logObject);

            Debug.Log($"{logMessage}\n{stackName}: {objectTypeAndParameters}\n{logObjectInformation}");
        }

        private static string FormatObjectInformation(object inputObject, int currentDepth, int maximumDepth)
        {
            if (inputObject == null) { return "OBJECT IS NULL"; }

            string returnString = "";
            System.Type inputObjectType = inputObject.GetType();
            string indent = Indent(currentDepth);

            if (inputObject is string || inputObjectType.IsPrimitive) { return inputObject.ToString(); }
            else if (inputObject is IDictionary inputDict)
            {
                string dictionaryContents = string.Join(
                    $",\n{indent}", inputDict.Cast<object>().Select(element =>
                        {
                            dynamic kvp = element;
                            string Key = ((object)kvp.Key).GetNameOrFormat(currentDepth, maximumDepth);
                            string Value = ((object)kvp.Value).GetNameOrFormat(currentDepth, maximumDepth);
                            return $"{Key}: {Value}";
                        }
                    )
                );
                returnString = $"{{\n{indent}{dictionaryContents}\n{Indent(currentDepth-1)}}}";
            }
            else if (inputObject is IEnumerable Enum)
            {
                returnString = "{\n" + indent + string.Join($",\n{indent}", Enum.Cast<object>().Select(element => element.GetNameOrFormat(currentDepth, maximumDepth))) + "\n" + Indent(currentDepth-1) + "}";
            }
            else if (true) { returnString = string.Empty; } // Will work with custom classes
            else { throw new Exception("ERROR: SHOULD NOT REACH THIS POINT"); }

            return returnString;
        }

        private static string Indent(int depth)
        {
            return string.Concat(Enumerable.Repeat("\t", depth));
        }

        private static string GetObjectTypeAndParameters(object inputObject)
        {
            if (inputObject == null) { return "OBJECT IS NULL"; }

            System.Type inputObjectType = (inputObject is System.Type) ? (System.Type)inputObject : inputObject.GetType();
            string inputObjectTypeName = inputObjectType.Name;
            string inputObjectParametersString = "";

            if (inputObjectType.IsArray) { return GetObjectTypeAndParameters(inputObjectType.GetElementType()) + "[]"; }

            if (inputObjectType.IsGenericType)
            {
                inputObjectTypeName = inputObjectTypeName.Split('`')[0];
                System.Type[] inputObjectParameters = inputObjectType.GetGenericArguments();
                inputObjectParametersString = "<" + string.Join(", ", inputObjectParameters.Select(arg => GetObjectTypeAndParameters(arg))) + ">";
            }

            return inputObjectTypeName + inputObjectParametersString;
        }

        private static bool HasNameProperty(this object inputObject) { return HasNameProperty(inputObject.GetType()); }
        private static bool HasNameProperty(this System.Type inputObjectType)
        {
            PropertyInfo property = inputObjectType.GetProperty("Name", BindingFlags.Public | BindingFlags.Instance);
            return (property != null);
        }

        private static string GetNameProperty(object inputObject)
        {
            System.Type inputObjectType = inputObject.GetType();
            if (inputObject.HasNameProperty()) { return inputObjectType.GetProperty("Name", BindingFlags.Public | BindingFlags.Instance).GetValue(inputObject, null).ToString(); }
            else { throw new Exception($"NON-STANDARD TYPE \"{inputObjectType.Name}\" LACKS \"Name\" PROPERTY"); }
        }

        private static string GetNameOrFormat(this object inputObject, int currentDepth, int maximumDepth)
        {
            if (currentDepth < maximumDepth)
            {
                return (inputObject.HasNameProperty()) ? GetNameProperty(inputObject) : FormatObjectInformation(inputObject, currentDepth+1, maximumDepth);
            }
            else if (inputObject is string || inputObject.GetType().IsPrimitive)
            {
                return inputObject.ToString();
            }
            else
            {
                return GetObjectTypeAndParameters(inputObject);
            }
        }

        private static string GetStack(Expression expression)
        {
            if (expression is MemberExpression memberExpression)
            {
                string stackPath = "";
                if (memberExpression.Expression != null) { stackPath = GetStack(memberExpression.Expression) + ((string.IsNullOrEmpty(GetStack(memberExpression.Expression))) ? "" : "."); }
                return (string.IsNullOrEmpty(stackPath)) ? memberExpression.Member.Name : $"{stackPath}{memberExpression.Member.Name}";
            }
            else if (expression is ConstantExpression constantExpression)
            {
                return (constantExpression.Value == null) ? constantExpression.GetType().Name : "";
            }
            else if (expression is UnaryExpression unaryExpression && unaryExpression.NodeType == ExpressionType.Convert)
            {
                return GetStack(unaryExpression.Operand);
            }
            else if (expression is ParameterExpression parameterExpression)
            {
                return parameterExpression.Name;
            }

            throw new Exception("Could not analyze stack");
        }
    }
}