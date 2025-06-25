using System.Collections;
using UnityEngine;

namespace Utils
{
    public static class Logger
    {
        public static void Log<T>(this T logObject, string logMessage = "")
        {
            string logObjectInformation = "";
            logMessage = AutoLogMessage(logObject, logMessage);
            Debug.Log($"{logMessage}\n{logObjectInformation}");
        }

        private static string AutoLogMessage(object inputObject, string inputMessage)
        {
            if (!string.IsNullOrEmpty(inputMessage)) { return inputMessage; }

            throw new System.Exception("ERROR: SHOULD NOT REACH THIS POINT");
        }
    }
}