using Assets.Scripts.Models;
using Assets.Scripts.Models.Bloons;
using Assets.Scripts.Models.Towers;
using Assets.Scripts.Models.Towers.Behaviors.Abilities;
using Assets.Scripts.Models.Towers.Behaviors.Attack;
using Assets.Scripts.Models.Towers.Projectiles;
using Assets.Scripts.Models.Towers.Weapons;
using Assets.Scripts.Utils;
using Inferno.Utilities;
using System.Linq;

namespace Inferno.Extensions {
    public static class ModelEXT {
        public static bool Matches(this Model model, string partialName) =>
            model.name.Contains(partialName);
        public static bool MatchesAny(this Model model, params string[] partialNames) =>
            partialNames.Any(pn => model.name.Contains(pn));

        public static bool Is(this Model model, Model toCompare) =>
            Helpers.IsEqualAndCanBeNull(model, toCompare);
        public static bool IsAny(this Model model, params Model[] toCompare) =>
            toCompare.Any(b => Helpers.IsEqualAndCanBeNull(model, b));

        public static T Copy<T>(this T model) where T : Model => model.Clone().Cast<T>();
        public static T Copy<T>(this Model model) where T : Model => model.Clone().Cast<T>();
    }
}