using Assets.Scripts.Models;
using Assets.Scripts.Models.Towers;
using Assets.Scripts.Models.Towers.Behaviors.Attack;
using Inferno.Extensions;
using MelonLoader;

namespace Inferno {
    class Main : MelonMod {
        private void test() {
            new Model("").Copy<TowerModel>();
        }
    }
}