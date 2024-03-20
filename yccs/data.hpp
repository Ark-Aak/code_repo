#include <bits/stdc++.h>

namespace Buff {

	enum BuffType {
		Physical = 1, Magical = 2, Reason = 4
	};

	struct Buff {
		BuffType type;
		int duration;
		int value;
	};

	typedef std::vector <Buff> BuffGroup;
}

using Buff::BuffGroup;

namespace SkillContent {

	enum DamageType {
		Physical = 1, Magical = 2, Reason = 4
	};

	enum SkillType {
		Active = 1, Passive = 2
	};

	enum CostType {
		AP = 1, HP = 2, IP = 4, PR = 8, MP = 16
	};

	enum SkillTarget {
		Single = 1, Multi = 2, All = 4
	};

	struct SkillDamage {
		DamageType type;
		int value;
		SkillTarget target;
	};

	struct SkillCost {
		CostType type;
		int value;
	};

	class Skill;
	typedef std::vector <SkillDamage> SkillDamageGroup;
	typedef std::vector <SkillCost> SkillCostGroup;
	typedef std::vector <Skill> SkillGroup;

	struct SkillSpecial {
		bool canChooseBackend;
		SkillDamage backendDamage;
		SkillGroup nextSkills;
	};

	class Skill {

	private:
		std::string name;
		std::string description;
		SkillType type;
		SkillDamageGroup damage;
		SkillCostGroup cost;
		SkillSpecial special;
		bool hasBuff;
		BuffGroup buff;

	public:

		std::string getName() { return name; }
		std::string getDescription() { return description; }
		SkillType getType() { return type; }
		SkillDamageGroup getDamage() { return damage; }
		SkillCostGroup getCost() { return cost; }
		SkillSpecial getSpecial() { return special; }

		Skill() {}
		Skill(std::string name, std::string description,
				SkillType type, SkillDamageGroup damage,
				SkillCostGroup cost, SkillSpecial special,
				bool hasBuff = false, BuffGroup buff = {}
			) {
			this -> name = name;
			this -> description = description;
			this -> type = type;
			this -> damage = damage;
			this -> cost = cost;
			this -> special = special;
			this -> hasBuff = hasBuff;
			this -> buff = buff;
		}
	};
}

using namespace SkillContent;

namespace CharacterContent {
    const int N = 300;
    std::map <std::string, int> IDT;
    class Character {

    private:
        int HP, SP, DM, DA, star;
        std::string name;
		SkillGroup skillGroup;

    public:

        int getHP() { return HP; }
        int getSP() { return SP; }
        int getDM() { return DM; }
        int getDA() { return DA; }
        int getStar() { return star; }
        std::string getName() { return name; }

        Character() {}
        Character(int HP, int SP, int DM, int DA, int star,
				std::string name, SkillGroup skillGroup) {
            this -> HP = HP;
            this -> SP = SP;
            this -> DM = DM;
            this -> DA = DA;
            this -> star = star;
            this -> name = name;
			this -> skillGroup = skillGroup;
        }
    };

	SkillGroup skillGroup[500] = {
		SkillGroup({
			Skill(
				"摸头杀",
				"消耗 3AP，获得 1PR，对一名角色造成 2物理伤害。",
				Active,
				{ { Physical, 2, Single } },
				{ { AP, 3 }, { PR, -1 } },
				{ true, { Physical, 1, All } }
			),
			Skill(
				"出题",
				"消耗 5IP，获得 1PR，对所有其他前台角色造成 4理智伤害，对所有其他后台角色造成 1物理伤害。",
				Active,
				{ { Reason, 2, All } },
				{ { IP, 5 }, { PR, -1 } },
				{ true, { Physical, 1, All } }
			),
			Skill(
				"AK 了就可以走了",
				"消耗 2PR 和 4IP，立即发动一次出题，且下次攻击 理智伤害+1。",
				Active,
				{ { Physical, 3, Single } },
				{ { AP, 3 }, { PR, -1 } },
				{ false, {} },
				true,
				{ {Buff::Reason, 1, 1} }
			),
		}),
	};

    Character character[500] = {
        Character(12,10,3,0,5,"lcrh", skillGroup[0]),
        Character(14,6,3,0,5,"zhl", skillGroup[1]),
        Character(14,8,4,0,4,"kmy", skillGroup[2]),
        Character(8,6,4,0,6,"cqy", skillGroup[3]),
        Character(16,4,4,0,4,"ljh", skillGroup[4]),
        Character(14,8,4,0,4,"cjx", skillGroup[5]),
        Character(10,13,3,0,6,"The King", skillGroup[6]),
        Character(16,6,3,0,4,"xxr", skillGroup[7]),
        Character(12,10,3,0,6,"sbb", skillGroup[8]),
        Character(12,10,3,0,5,"zzs", skillGroup[9]),
        Character(12,10,3,0,6,"lx", skillGroup[10]),
        Character(12,12,4,0,4,"xcs", skillGroup[11]),
        Character(10,10,3,0,5,"hy", skillGroup[12]),
        Character(14,8,3,0,4,"hst", skillGroup[13]),
        Character(20,2,3,0,5,"异格·xxr·男同", skillGroup[14]),
        Character(20,2,2,0,4,"syd", skillGroup[15]),
        Character(12,6,5,0,6,"异格·ljh·dp", skillGroup[16]),
        Character(8,15,4,0,6,"异格·lcrh·出题", skillGroup[17]),
        Character(10,10,4,0,5,"zqh", skillGroup[18]),
        Character(8,8,3,0,5,"zaa", skillGroup[19]),
        Character(20,5,5,0,4,"zcq", skillGroup[20]),
        Character(10,10,3,0,5,"pyy", skillGroup[21]),
        Character(8,8,10,0,4,"dw", skillGroup[22]),
        Character(12,12,3,0,6,"KAxdd", skillGroup[23]),
    };
}
