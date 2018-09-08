// アクション一覧
enum Actions {
    attack,
    defence,
}

// ゲーム中に使用されるセーブデータ
type saveData = {
    actionType : Actions,
    chara : number,
    param : any
    /**
     * MEMO actionTypeによって型を変えたい。
     * attackならsaveParamAttack等。
     */
}

// キャラクタステータス
type Status = {
    hp : number,
    mp? : number
}

// キャラクタクラス
class Character {
    public id : number;
    public status : Status;
    
    constructor(id : number) {
        this.id = id;
        this.status = {
            hp : Math.floor(Math.random() * (200 + 1 - 100)) + 100
        }
    }

    public attackTo(target : Character) {
        const damage : number = Math.floor(Math.random() * (50 + 1 - 10)) + 10;
        target.recieveAttack(damage);
        return damage;
    }

    public recieveAttack(damage : number) {
        this.status.hp -= damage;
    }
}

// ゲーム継続しているか
const isGameStillGoing = characters => {
    return characters.some(v => v.status.hp >= 0);
}

// 攻撃対象を取得
const getNextTarget = (index : number, characters : Character[]) => {
    return (index === 0) ? characters[1] : characters[0]
};

const gameStart = () => {
    let saveDataArray : saveData[] = [];
    const characters : Character[] = [new Character(0), new Character(1)];

    while(isGameStillGoing(characters)){
        characters.forEach((chara, index) => {
            const target : Character = getNextTarget(index, characters);
            const damage : number = chara.attackTo(target);
            console.log(`${target.id}に${damage}のダメージ, ${target.status.hp + damage} => ${target.status.hp}`);

            const result : saveData = {
                actionType : Actions.attack,
                chara : chara.id,
                param : {
                    attackTo : target.id,
                    damage : damage
                }
            }
            saveDataArray.push(result);
        });
    }

    return saveDataArray;
}

console.log(gameStart());