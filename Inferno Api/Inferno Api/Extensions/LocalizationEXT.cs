using Assets.Scripts.Unity.Localization;

namespace Inferno.Extensions {
    public static class LocalizationEXT {
        public static void Add(this LocalizationManager localizationManager, string key, string value) => localizationManager.textTable.Add(key, value);
    }
}