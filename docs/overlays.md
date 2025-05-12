# Overlays
In Lego Battles, each overlay contains the logic for a mission. The logic consists of a function that handles events (a single number) and sets up objectives based on it.

Note that this data was extracted by emulating the THUMB code and grabbing values from registers at certain points. I've not had time to create an ARM emulator yet, and for some reason the wizard's campaign loading functions are all in ARM, so they are not included here.

ARM emulator code is in the [Open Lego Battles repo.](https://github.com/LiruJ/OpenLegoBattles)

 ID  | Name                          | Map Name | Act | Mission
-----|-------------------------------|----------|-----|--------
`01` | Criminal Minds                | ma2_1    | 2   | 1  
`02` | Running on Empty              | ma3_1    | 3   | 1  
`03` | Impact!                       | ma1_1    | 1   | 1  
`04` | CryoLab Down                  | ma2_2    | 2   | 2  
`05` | Guidance                      | ma3_2    | 3   | 2  
`06` | Shock and Awe                 | ma1_3    | 1   | 3  
`07` | Hotwired                      | ma2_3    | 2   | 3  
`08` | Freedom                       | ma3_4    | 3   | 3  
`09` | Taken                         | ma1_4    | 1   | 2  
`10` | Supply Lines                  | ma2_5    | 2   | 4  
`11` | Feed The Fire                 | ma3_5    | 3   | 4  
`12` | Captured                      | ma1_6    | 1   | 4  
`13` | The Final Countdown           | ma3_6    | 3   | 5  
`14` | Missing in Action             | ma2_6    | 2   | 5  
`15` | Exodus                        | ma1_7    | 1   | 5  
`16` | The Red Planet                | mh1_1    | 1   | 1  
`17` | A Hard Place                  | mh2_1    | 2   | 1  
`18` | Ancient Treasure              | mh3_2    | 3   | 1  
`19` | Something’s Out There         | mh1_2    | 1   | 2  
`20` | Drop Zone                     | mh3_3    | 3   | 2  
`21` | Search For Scum               | mh2_3    | 2   | 3  
`22` | A Purple Lode                 | mh1_3    | 1   | 3  
`23` | Purple Haze                   | mh2_4    | 2   | 2  
`24` | Stranded                      | mh2_5    | 2   | 4  
`25` | Head Start                    | mh3_5    | 3   | 3  
`26` | Purple is the New Green       | mh1_5    | 1   | 5  
`27` | Mothership Connection         | mh3_6    | 3   | 4  
`28` | Retaliation                   | mh1_6    | 1   | 4  
`29` | The Motherlode                | mh2_6    | 2   | 5  
`30` | Orders from Above             | mh1_7    | 1   | 6  
`31` | Monkey Business               | pi3_1    | 3   | 1  
`32` | The Prisoner                  | pi2_1    | 2   | 1  
`33` | Royal Commission              | pi1_1    | 1   | 1  
`34` | Royal Territory               | pi3_2    | 3   | 2  
`35` | Sitting Ducks                 | pi2_2    | 2   | 2  
`36` | The Canary                    | pi1_2    | 1   | 2  
`37` | Abandoned Outposts            | pi2_3    | 2   | 3  
`38` | Raiding Party                 | pi1_3    | 1   | 3  
`39` | Sneak Attack                  | pi3_3    | 3   | 3  
`40` | Sabotage                      | pi1_4    | 1   | 4  
`41` | Temple Raid                   | pi2_4    | 2   | 4  
`42` | All Mine                      | pi3_6    | 3   | 4  
`43` | Mutiny on Brickbeard’s Bounty | pi2_5    | 2   | 5  
`44` | Precious Cargo                | pi1_5    | 1   | 5  
`45` | End Game                      | pi3_5    | 3   | 5  
`46` | The Maze                      | ck3_1    | 3   | 1  
`47` | Dark Shadows                  | ck1_1    | 1   | 1  
`48` | Old Allies                    | ck2_1    | 2   | 1  
`49` | War Machines                  | ck2_2    | 2   | 2  
`50` | Costly Distractions           | ck1_2    | 1   | 2  
`51` | Grave Mission                 | ck3_2    | 3   | 2  
`52` | 1000 Tree Woods               | ck1_3    | 1   | 4  
`53` | Perilous Journey              | ck3_3    | 3   | 3  
`54` | Stand Fast                    | ck2_3    | 2   | 3  
`55` | The Great Library             | ck1_4    | 1   | 3  
`56` | Confrontation                 | ck3_4    | 3   | 4  
`57` | Knowledge Of The Ancients     | ck2_4    | 2   | 4  
`58` | Forgotten Passage             | ck2_5    | 2   | 5  
`59` | The Barren Wasteland          | ck2_6    | 2   | 6  
`60` | Bridge the Gap                | ck1_6    | 1   | 5  
`61` | Put to Sea                    | pp1_1    | 1   | 1  
`62` | Adrift                        | pp3_1    | 3   | 1  
`63` | Hidden Treasure               | pp2_1    | 2   | 1  
`64` | Outpost Offensive             | pp1_2    | 1   | 2  
