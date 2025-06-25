using UnityEngine;

namespace Utils
{
    public static class Logger
    {
        public static void Log<T>(this T logObject, string logMessage = "")
        {
            string logObjectInformation = "";
            Debug.Log($"{logMessage}\n{logObjectInformation}");
        }
    }
}