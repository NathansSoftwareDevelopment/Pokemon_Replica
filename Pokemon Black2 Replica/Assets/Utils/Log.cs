using System.Collections;
using System.Linq;
using System.Reflection;
using UnityEngine;

namespace Utils
{
    public static class Logger
    {
        public static void Log<T>(this T logObject, string logMessage = "")
        {
            string logObjectInformation;
            logMessage = AutoLogMessage(logObject, logMessage);
            logObjectInformation = FormatObjectInformation(logObject);
            string logObjectType = logObject.GetType().Name;
            string logObjectParameters = string.Join(", ", logObject.GetType().GetGenericArguments().Select(arg => arg.Name));
            if (logObjectParameters != "") { logObjectParameters = "<" + logObjectParameters + ">"; }
            Debug.Log($"{logMessage}\n{logObjectType}{logObjectParameters}\n{logObjectInformation}");
        }

        private static string AutoLogMessage(object inputObject, string inputMessage)
        {
            string returnMessage = string.Empty;
            if (!string.IsNullOrEmpty(inputMessage)) { returnMessage = inputMessage; }
            else if (inputObject is IEnumerable || inputObject is IDictionary) { returnMessage = inputObject.GetType().Name; }
            else { returnMessage = GetNameProperty(inputObject); }


            if (string.IsNullOrEmpty(returnMessage)) { throw new System.Exception("ERROR: SHOULD NOT REACH THIS POINT"); }
            else { return returnMessage; }
        }

        private static string FormatObjectInformation(object inputObject)
        {
            string returnString = "";
            System.Type objectType = inputObject.GetType();

            if (inputObject == null) { returnString = "OBJECT IS NULL"; }
            else if (inputObject is IEnumerable)
            {
                
            }
            else if (inputObject is IDictionary)
            {

            }
            else if (inputObject is string || (objectType.IsPrimitive)) { return inputObject.ToString(); }
            else if (true) { returnString = string.Empty; } // Will work with custom classes
            else { throw new System.Exception("ERROR: SHOULD NOT REACH THIS POINT"); }

            return returnString;
        }

        private static string GetNameProperty(object inputObject)
        {
            System.Type inputObjectType = inputObject.GetType();
            PropertyInfo property = inputObjectType.GetProperty("Name", BindingFlags.Public | BindingFlags.Instance);
            if (property == null) { throw new System.Exception($"NON-STANDARD TYPE \"{inputObjectType.Name}\" LACKS \"Name\" PROPERTY"); }
            else
            {
                return property.GetValue(inputObject, null).ToString();
            }
        }
    }
}