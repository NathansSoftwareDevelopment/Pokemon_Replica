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
        public static void Log<T>(Expression<Func<T>> expression, string logMessage = "")
        {
            string stackName = GetStack(expression.Body);
            object logObject = expression.Compile().Invoke();

            string logObjectInformation;
            logObjectInformation = FormatObjectInformation(logObject);
            string objectTypeAndParameters = GetObjectTypeAndParameters(logObject);
            Debug.Log($"{logMessage}\n{stackName}: {objectTypeAndParameters}\n{logObjectInformation}");
        }

        private static string FormatObjectInformation(object inputObject)
        {
            string returnString = "";
            System.Type inputObjectType = inputObject.GetType();

            if (inputObject == null) { returnString = "OBJECT IS NULL"; }
            else if (inputObject is IDictionary)
            {
                return GetObjectTypeAndParameters(inputObject);
            }
            else if (inputObject is IEnumerable Enum)
            {
                returnString = "{\n" + "\t" + string.Join(",\n\t", Enum.Cast<object>().Select(element => (element.GetType().GetProperty("Name", BindingFlags.Public | BindingFlags.Instance) != null) ? GetNameProperty(element) : FormatObjectInformation(element))) + "\n}";
            }
            else if (inputObject is string || inputObjectType.IsPrimitive) { return inputObject.ToString(); }
            else if (true) { returnString = string.Empty; } // Will work with custom classes
            else { throw new Exception("ERROR: SHOULD NOT REACH THIS POINT"); }

            return returnString;
        }

        private static string GetObjectTypeAndParameters(object inputObject)
        {
            string logObjectType = inputObject.GetType().Name;
            string logObjectParameters = string.Join(", ", inputObject.GetType().GetGenericArguments().Select(arg => arg.Name));
            if (logObjectParameters != "") { logObjectParameters = "<" + logObjectParameters + ">"; }
            return logObjectType + logObjectParameters;
        }

        private static bool HasNameProperty(this System.Type inputObjectType)
        {
            PropertyInfo property = inputObjectType.GetProperty("Name", BindingFlags.Public | BindingFlags.Instance);
            return (property != null);
        }

        private static string GetNameProperty(object inputObject)
        {
            System.Type inputObjectType = inputObject.GetType();
            PropertyInfo property = inputObjectType.GetProperty("Name", BindingFlags.Public | BindingFlags.Instance);
            if (property == null) { throw new Exception($"NON-STANDARD TYPE \"{inputObjectType.Name}\" LACKS \"Name\" PROPERTY"); }
            else
            {
                return property.GetValue(inputObject, null).ToString();
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