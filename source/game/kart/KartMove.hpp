#pragma once

#include <rk_types.h>

#include <decomp.h>

#include <game/kart/KartObjectProxy.hpp>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x80577fc4..0x8057811c
UNKNOWN_FUNCTION(PlayerSub10_construct);
// PAL: 0x8057811c..0x8057815c
UNKNOWN_FUNCTION(PlayerBoost_destroy);
// PAL: 0x8057815c..0x8057819c
UNKNOWN_FUNCTION(unk_8057815c);
// PAL: 0x8057819c..0x805781dc
UNKNOWN_FUNCTION(unk_8057819c);
// PAL: 0x805781dc..0x8057821c
UNKNOWN_FUNCTION(unk_805781dc);
// PAL: 0x8057821c..0x8057829c
UNKNOWN_FUNCTION(PlayerSub10_initTrickZipper);
// PAL: 0x8057829c..0x805784d4
UNKNOWN_FUNCTION(PlayerSub10_resetHard);
// PAL: 0x805784d4..0x805788dc
UNKNOWN_FUNCTION(PlayerSub10_init2);
// PAL: 0x805788dc..0x80579960
UNKNOWN_FUNCTION(PlayerSub10_update);
// PAL: 0x80579960..0x80579968
UNKNOWN_FUNCTION(unk_80579960);
// PAL: 0x80579968..0x805799ac
UNKNOWN_FUNCTION(PlayerSub10_updateHopPhysics);
// PAL: 0x805799ac..0x80579a50
UNKNOWN_FUNCTION(PlayerSub10_respawn);
// PAL: 0x80579a50..0x80579ce4
UNKNOWN_FUNCTION(unk_80579a50);
// PAL: 0x80579ce4..0x80579da8
UNKNOWN_FUNCTION(unk_80579ce4);
// PAL: 0x80579da8..0x80579f20
UNKNOWN_FUNCTION(unk_80579da8);
// PAL: 0x80579f20..0x80579f6c
UNKNOWN_FUNCTION(unk_80579f20);
// PAL: 0x80579f6c..0x80579fe4
UNKNOWN_FUNCTION(unk_80579f6c);
// PAL: 0x80579fe4..0x8057a13c
UNKNOWN_FUNCTION(PlayerSub10_somethingWheelieBump);
// PAL: 0x8057a13c..0x8057a140
UNKNOWN_FUNCTION(unk_8057a13c);
// PAL: 0x8057a140..0x8057a8b4
UNKNOWN_FUNCTION(PlayerSub10_updateDirs);
// PAL: 0x8057a8b4..0x8057ab68
UNKNOWN_FUNCTION(PlayerSub10_updateTurn);
// PAL: 0x8057ab68..0x8057b028
UNKNOWN_FUNCTION(PlayerSub10_updateVehicleSpeed);
// PAL: 0x8057b028..0x8057b108
UNKNOWN_FUNCTION(unk_8057b028);
// PAL: 0x8057b108..0x8057b29c
UNKNOWN_FUNCTION(PlayerSub10_computeWallCollisionSpeedFactor);
// PAL: 0x8057b29c..0x8057b2a0
UNKNOWN_FUNCTION(unk_8057b29c);
// PAL: 0x8057b2a0..0x8057b77c
UNKNOWN_FUNCTION(unk_8057b2a0);
// PAL: 0x8057b77c..0x8057b868
UNKNOWN_FUNCTION(unk_8057b77c);
// PAL: 0x8057b868..0x8057b99c
UNKNOWN_FUNCTION(get_acceleration_from_speed);
// PAL: 0x8057b99c..0x8057b9ac
UNKNOWN_FUNCTION(PlayerSub10_setBulletHardSpeedLimit);
// PAL: 0x8057b9ac..0x8057b9bc
UNKNOWN_FUNCTION(PlayerSub10_setRegularHardSpeedLimit);
// PAL: 0x8057b9bc..0x8057c3c8
UNKNOWN_FUNCTION(PlayerSub10_updateAcceleration);
// PAL: 0x8057c3c8..0x8057c3d4
UNKNOWN_FUNCTION(PlayerSub10_getWheelieSoftSpeedLimitBonus);
// PAL: 0x8057c3d4..0x8057c5e8
UNKNOWN_FUNCTION(PlayerSub10_updateOffroad);
// PAL: 0x8057c5e8..0x8057c69c
UNKNOWN_FUNCTION(unk_8057c5e8);
// PAL: 0x8057c69c..0x8057cdd4
UNKNOWN_FUNCTION(PlayerSub10_updateRotation);
// PAL: 0x8057cdd4..0x8057cf0c
UNKNOWN_FUNCTION(unk_8057cdd4);
// PAL: 0x8057cf0c..0x8057d1d4
UNKNOWN_FUNCTION(PlayerSub10_updateVehicleRotationVector);
// PAL: 0x8057d1d4..0x8057d398
UNKNOWN_FUNCTION(PlayerSub10_updateStandstillBoostRot);
// PAL: 0x8057d398..0x8057d888
UNKNOWN_FUNCTION(PlayerSub10_updateTop);
// PAL: 0x8057d888..0x8057da18
UNKNOWN_FUNCTION(PlayerSub10_updateTopDuringAirtime);
// PAL: 0x8057da18..0x8057da5c
UNKNOWN_FUNCTION(PlayerSub10_canHop);
// PAL: 0x8057da5c..0x8057dc40
UNKNOWN_FUNCTION(PlayerSub10_hop);
// PAL: 0x8057dc40..0x8057dc44
UNKNOWN_FUNCTION(PlayerSub10_cancelWheelie);
// PAL: 0x8057dc44..0x8057e0dc
UNKNOWN_FUNCTION(PlayerSub10_updateManualDrift);
// PAL: 0x8057e0dc..0x8057e348
UNKNOWN_FUNCTION(PlayerSub10_updateAutoDrift);
// PAL: 0x8057e348..0x8057e3f4
UNKNOWN_FUNCTION(unk_8057e348);
// PAL: 0x8057e3f4..0x8057e638
UNKNOWN_FUNCTION(PlayerSub10_startManualDrift);
// PAL: 0x8057e638..0x8057e6f4
UNKNOWN_FUNCTION(unk_8057e638);
// PAL: 0x8057e6f4..0x8057e77c
UNKNOWN_FUNCTION(unk_8057e6f4);
// PAL: 0x8057e77c..0x8057e804
UNKNOWN_FUNCTION(unk_8057e77c);
// PAL: 0x8057e804..0x8057e99c
UNKNOWN_FUNCTION(PlayerSub10_updateHopAndSlipdrift);
// PAL: 0x8057e99c..0x8057ea50
UNKNOWN_FUNCTION(unk_8057e99c);
// PAL: 0x8057ea50..0x8057ea94
UNKNOWN_FUNCTION(unk_8057ea50);
// PAL: 0x8057ea94..0x8057eab8
UNKNOWN_FUNCTION(unk_8057ea94);
// PAL: 0x8057eab8..0x8057ec28
UNKNOWN_FUNCTION(unk_8057eab8);
// PAL: 0x8057ec28..0x8057ed20
UNKNOWN_FUNCTION(unk_8057ec28);
// PAL: 0x8057ed20..0x8057ed34
UNKNOWN_FUNCTION(unk_8057ed20);
// PAL: 0x8057ed34..0x8057ed8c
UNKNOWN_FUNCTION(unk_8057ed34);
// PAL: 0x8057ed8c..0x8057ee50
UNKNOWN_FUNCTION(unk_8057ed8c);
// PAL: 0x8057ee50..0x8057efe0
UNKNOWN_FUNCTION(PlayerSub10_updateMtCharge);
// PAL: 0x8057efe0..0x8057efec
UNKNOWN_FUNCTION(getMaxMtCharge__Q24Kart8KartMoveFv);
// PAL: 0x8057efec..0x8057eff8
UNKNOWN_FUNCTION(getMaxSmtCharge__Q24Kart8KartMoveFv);
// PAL: 0x8057eff8..0x8057f024
UNKNOWN_FUNCTION(getAppliedHopStickX__Q24Kart8KartMoveFv);
// PAL: 0x8057f024..0x8057f05c
UNKNOWN_FUNCTION(unk_8057f024);
// PAL: 0x8057f05c..0x8057f090
UNKNOWN_FUNCTION(unk_8057f05c);
// PAL: 0x8057f090..0x8057f1d0
UNKNOWN_FUNCTION(unk_8057f090);
// PAL: 0x8057f1d0..0x8057f3d8
UNKNOWN_FUNCTION(unk_8057f1d0);
// PAL: 0x8057f3d8..0x8057f630
UNKNOWN_FUNCTION(PlayerSub10_activateMushroom);
// PAL: 0x8057f630..0x8057f7a8
UNKNOWN_FUNCTION(unk_8057f630);
// PAL: 0x8057f7a8..0x8057f96c
UNKNOWN_FUNCTION(PlayerSub10_endTrick);
// PAL: 0x8057f96c..0x8057fb6c
UNKNOWN_FUNCTION(PlayerSub10_activateZipperBoost);
// PAL: 0x8057fb6c..0x8057fd18
UNKNOWN_FUNCTION(unk_8057fb6c);
// PAL: 0x8057fd18..0x805800bc
UNKNOWN_FUNCTION(PlayerSub10_tryStartJumpPad);
// PAL: 0x805800bc..0x80580268
UNKNOWN_FUNCTION(unk_805800bc);
// PAL: 0x80580268..0x805803f0
UNKNOWN_FUNCTION(PlayerSub10_activateStar);
// PAL: 0x805803f0..0x80580438
UNKNOWN_FUNCTION(unk_805803f0);
// PAL: 0x80580438..0x8058051c
UNKNOWN_FUNCTION(PlayerSub10_applyLightning);
// PAL: 0x8058051c..0x805805ec
UNKNOWN_FUNCTION(unk_8058051c);
// PAL: 0x805805ec..0x80580648
UNKNOWN_FUNCTION(unk_805805ec);
// PAL: 0x80580648..0x805806a4
UNKNOWN_FUNCTION(unk_80580648);
// PAL: 0x805806a4..0x80580768
UNKNOWN_FUNCTION(unk_805806a4);
// PAL: 0x80580768..0x80580778
UNKNOWN_FUNCTION(unk_80580768);
// PAL: 0x80580778..0x80580998
UNKNOWN_FUNCTION(PlayerSub10_applyLightningEffect);
// PAL: 0x80580998..0x80580a84
UNKNOWN_FUNCTION(unk_80580998);
// PAL: 0x80580a84..0x80580b14
UNKNOWN_FUNCTION(unk_80580a84);
// PAL: 0x80580b14..0x80580cdc
UNKNOWN_FUNCTION(PlayerSub10_activateMega);
// PAL: 0x80580cdc..0x80580dc0
UNKNOWN_FUNCTION(unk_80580cdc);
// PAL: 0x80580dc0..0x80580f28
UNKNOWN_FUNCTION(unk_80580dc0);
// PAL: 0x80580f28..0x80580f9c
UNKNOWN_FUNCTION(unk_80580f28);
// PAL: 0x80580f9c..0x80581034
UNKNOWN_FUNCTION(unk_80580f9c);
// PAL: 0x80581034..0x805810a8
UNKNOWN_FUNCTION(unk_80581034);
// PAL: 0x805810a8..0x805813a4
UNKNOWN_FUNCTION(unk_805810a8);
// PAL: 0x805813a4..0x805813e8
UNKNOWN_FUNCTION(unk_805813a4);
// PAL: 0x805813e8..0x8058160c
UNKNOWN_FUNCTION(unk_805813e8);
// PAL: 0x8058160c..0x80581720
UNKNOWN_FUNCTION(unk_8058160c);
// PAL: 0x80581720..0x8058173c
UNKNOWN_FUNCTION(setScale__Q24Kart8KartMoveFQ23EGG8Vector3f);
// PAL: 0x8058173c..0x80581778
UNKNOWN_FUNCTION(unk_8058173c);
// PAL: 0x80581778..0x80581824
UNKNOWN_FUNCTION(unk_80581778);
// PAL: 0x80581824..0x8058196c
UNKNOWN_FUNCTION(unk_80581824);
// PAL: 0x8058196c..0x805819a8
UNKNOWN_FUNCTION(unk_8058196c);
// PAL: 0x805819a8..0x80581a24
UNKNOWN_FUNCTION(unk_805819a8);
// PAL: 0x80581a24..0x80581a28
UNKNOWN_FUNCTION(empty__Q24Kart8KartMoveFl);
// PAL: 0x80581a28..0x80581a40
UNKNOWN_FUNCTION(PlayerSub10_activateTc);
// PAL: 0x80581a40..0x80581a58
UNKNOWN_FUNCTION(PlayerSub10_deactivateTc);
// PAL: 0x80581a58..0x80581b1c
UNKNOWN_FUNCTION(PlayerSub10_applyInk);
// PAL: 0x80581b1c..0x80581c70
UNKNOWN_FUNCTION(PlayerSub10_updateInk);
// PAL: 0x80581c70..0x80581c90
UNKNOWN_FUNCTION(unk_80581c70);
// PAL: 0x80581c90..0x8058212c
UNKNOWN_FUNCTION(PlayerSub10_somethingRespawnBoost);
// PAL: 0x8058212c..0x80582278
UNKNOWN_FUNCTION(PlayerSub10_applyStartBoost);
// PAL: 0x80582278..0x805823a4
UNKNOWN_FUNCTION(unk_80582278);
// PAL: 0x805823a4..0x80582488
UNKNOWN_FUNCTION(unk_805823a4);
// PAL: 0x80582488..0x805824c8
UNKNOWN_FUNCTION(unk_80582488);
// PAL: 0x805824c8..0x805824f0
UNKNOWN_FUNCTION(unk_805824c8);
// PAL: 0x805824f0..0x80582530
UNKNOWN_FUNCTION(unk_805824f0);
// PAL: 0x80582530..0x80582694
UNKNOWN_FUNCTION(PlayerSub10_tryEndJumpPad);
// PAL: 0x80582694..0x80582804
UNKNOWN_FUNCTION(PlayerSub10_updateBoost);
// PAL: 0x80582804..0x805828cc
UNKNOWN_FUNCTION(unk_80582804);
// PAL: 0x805828cc..0x80582d94
UNKNOWN_FUNCTION(unk_805828cc);
// PAL: 0x80582d94..0x80582db4
UNKNOWN_FUNCTION(unk_80582d94);
// PAL: 0x80582db4..0x80582dd8
UNKNOWN_FUNCTION(unk_80582db4);
// PAL: 0x80582dd8..0x80582e34
UNKNOWN_FUNCTION(unk_80582dd8);
// PAL: 0x80582e34..0x80582f38
UNKNOWN_FUNCTION(unk_80582e34);
// PAL: 0x80582f38..0x80582f58
UNKNOWN_FUNCTION(unk_80582f38);
// PAL: 0x80582f58..0x80582f7c
UNKNOWN_FUNCTION(unk_80582f58);
// PAL: 0x80582f7c..0x80582f9c
UNKNOWN_FUNCTION(unk_80582f7c);
// PAL: 0x80582f9c..0x8058327c
UNKNOWN_FUNCTION(PlayerSub10_releaseMt);
// PAL: 0x8058327c..0x805832c4
UNKNOWN_FUNCTION(unk_8058327c);
// PAL: 0x805832c4..0x805832e4
UNKNOWN_FUNCTION(unk_805832c4);
// PAL: 0x805832e4..0x80583424
UNKNOWN_FUNCTION(clearBoost__Q24Kart8KartMoveFv);
// PAL: 0x80583424..0x8058348c
UNKNOWN_FUNCTION(unk_80583424);
// PAL: 0x8058348c..0x80583658
UNKNOWN_FUNCTION(unk_8058348c);
// PAL: 0x80583658..0x805837cc
UNKNOWN_FUNCTION(unk_80583658);
// PAL: 0x805837cc..0x80583b84
UNKNOWN_FUNCTION(unk_805837cc);
// PAL: 0x80583b84..0x80583b88
UNKNOWN_FUNCTION(unk_80583b84);
// PAL: 0x80583b88..0x80583f2c
UNKNOWN_FUNCTION(PlayerSub10_updateStickyRoad);
// PAL: 0x80583f2c..0x80584044
UNKNOWN_FUNCTION(unk_80583f2c);
// PAL: 0x80584044..0x80584334
UNKNOWN_FUNCTION(PlayerSub10_setInitialPhysicsValues);
// PAL: 0x80584334..0x80584648
UNKNOWN_FUNCTION(PlayerSub10_doRespawn);
// PAL: 0x80584648..0x8058473c
UNKNOWN_FUNCTION(unk_80584648);
// PAL: 0x8058473c..0x80584928
UNKNOWN_FUNCTION(unk_8058473c);
// PAL: 0x80584928..0x8058492c
UNKNOWN_FUNCTION(unk_80584928);
// PAL: 0x8058492c..0x80584930
UNKNOWN_FUNCTION(unk_8058492c);
// PAL: 0x80584930..0x8058498c
UNKNOWN_FUNCTION(unk_80584930);
// PAL: 0x8058498c..0x80584d58
UNKNOWN_FUNCTION(PlayerSub10_enterCannon);
// PAL: 0x80584d58..0x805852c8
UNKNOWN_FUNCTION(PlayerSub10_updateCannon);
// PAL: 0x805852c8..0x8058539c
UNKNOWN_FUNCTION(unk_805852c8);
// PAL: 0x8058539c..0x805855bc
UNKNOWN_FUNCTION(PlayerPointers_getCannonPosAndDir);
// PAL: 0x805855bc..0x805858ac
UNKNOWN_FUNCTION(unk_805855bc);
// PAL: 0x805858ac..0x80585a04
UNKNOWN_FUNCTION(PlayerSub10_activateBullet);
// PAL: 0x80585a04..0x80585a28
UNKNOWN_FUNCTION(unk_80585a04);
// PAL: 0x80585a28..0x80585a60
UNKNOWN_FUNCTION(unk_80585a28);
// PAL: 0x80585a60..0x80585aa0
UNKNOWN_FUNCTION(unk_80585a60);
// PAL: 0x80585aa0..0x80585ae8
UNKNOWN_FUNCTION(unk_80585aa0);
// PAL: 0x80585ae8..0x80585af8
UNKNOWN_FUNCTION(unk_80585ae8);
// PAL: 0x80585af8..0x805860bc
UNKNOWN_FUNCTION(unk_80585af8);
// PAL: 0x805860bc..0x8058677c
UNKNOWN_FUNCTION(unk_805860bc);
// PAL: 0x8058677c..0x805869dc
UNKNOWN_FUNCTION(unk_8058677c);
// PAL: 0x805869dc..0x80586d18
UNKNOWN_FUNCTION(PlayerSub10_updateDiving);
// PAL: 0x80586d18..0x80586db4
UNKNOWN_FUNCTION(unk_80586d18);
// PAL: 0x80586db4..0x80586e90
UNKNOWN_FUNCTION(unk_80586db4);
// PAL: 0x80586e90..0x80586fa8
UNKNOWN_FUNCTION(unk_80586e90);
// PAL: 0x80586fa8..0x805874c0
UNKNOWN_FUNCTION(PlayerSub10_updateSlipstream);
// PAL: 0x805874c0..0x8058758c
UNKNOWN_FUNCTION(unk_805874c0);
// PAL: 0x8058758c..0x80587590
UNKNOWN_FUNCTION(PlayerSub10_updateWheelie);
// PAL: 0x80587590..0x80587938
UNKNOWN_FUNCTION(PlayerSub10_updateSpecialFloor);
// PAL: 0x80587938..0x805879a4
UNKNOWN_FUNCTION(unk_80587938);
// PAL: 0x805879a4..0x80587b30
UNKNOWN_FUNCTION(unk_805879a4);
// PAL: 0x80587b30..0x80587b78
UNKNOWN_FUNCTION(PlayerSub10Bike_init);
// PAL: 0x80587b78..0x80587bb8
UNKNOWN_FUNCTION(PlayerSub10_destroy);
// PAL: 0x80587bb8..0x80587c54
UNKNOWN_FUNCTION(PlayerSub10Bike_initTrickZipper);
// PAL: 0x80587c54..0x80587d00
UNKNOWN_FUNCTION(PlayerSub10Bike_setTurnParams);
// PAL: 0x80587d00..0x80587d64
UNKNOWN_FUNCTION(PlayerSub10Bike_init2);
// PAL: 0x80587d64..0x80587d68
UNKNOWN_FUNCTION(PlayerSub10Bike_updateWheelie);
// PAL: 0x80587d68..0x80588324
UNKNOWN_FUNCTION(PlayerSub10Bike_updateVehicleRotationVector);
// PAL: 0x80588324..0x80588350
UNKNOWN_FUNCTION(PlayerSub10Bike_getWheelieSoftSpeedLimitBonus);
// PAL: 0x80588350..0x805883c4
UNKNOWN_FUNCTION(PlayerSub10Bike_startWheelie);
// PAL: 0x805883c4..0x805883f4
UNKNOWN_FUNCTION(PlayerSub10Bike_cancelWheelie);
// PAL: 0x805883f4..0x80588798
UNKNOWN_FUNCTION(unk_805883f4);
// PAL: 0x80588798..0x80588860
UNKNOWN_FUNCTION(PlayerSub10Bike_tryStartWheelie);
// PAL: 0x80588860..0x80588888
UNKNOWN_FUNCTION(unk_80588860);
// PAL: 0x80588888..0x80588950
UNKNOWN_FUNCTION(PlayerSub10Bike_updateMtCharge);
// PAL: 0x80588950..0x80588b30
UNKNOWN_FUNCTION(unk_80588950);
// PAL: 0x80588b30..0x80588b58
UNKNOWN_FUNCTION(unk_80588b30);
// PAL: 0x80588b58..0x80588cac
UNKNOWN_FUNCTION(unk_80588b58);
// PAL: 0x80588cac..0x80588d28
UNKNOWN_FUNCTION(unk_80588cac);
// PAL: 0x80588d28..0x80588d74
UNKNOWN_FUNCTION(PlayerBoost_construct);
// PAL: 0x80588d74..0x80588db0
UNKNOWN_FUNCTION(PlayerBoost_reset);
// PAL: 0x80588db0..0x80588e18
UNKNOWN_FUNCTION(PlayerBoost_activate);
// PAL: 0x80588e18..0x80588e24
UNKNOWN_FUNCTION(unk_80588e18);
// PAL: 0x80588e24..0x80588fc0
UNKNOWN_FUNCTION(PlayerBoost_update);
// PAL: 0x80588fc0..0x80588fd0
UNKNOWN_FUNCTION(unk_80588fc0);
// PAL: 0x80588fd0..0x80588fe0
UNKNOWN_FUNCTION(unk_80588fd0);
// PAL: 0x80588fe0..0x80589024
UNKNOWN_FUNCTION(PlayerSub10Bike_checkWheelieSpeed);
// PAL: 0x80589024..0x80589030
UNKNOWN_FUNCTION(getStarDuration);
// PAL: 0x80589030..0x8058905c
UNKNOWN_FUNCTION(unk_80589030);
// PAL: 0x8058905c..0x805890b0
UNKNOWN_FUNCTION(unk_8058905c);
// PAL: 0x805890b0..0x80589118
UNKNOWN_FUNCTION(unk_805890b0);
// PAL: 0x80589118..0x805891c0
UNKNOWN_FUNCTION(unk_80589118);
// PAL: 0x805891c0..0x8058920c
UNKNOWN_FUNCTION(unk_805891c0);
// PAL: 0x8058920c..0x80589230
UNKNOWN_FUNCTION(unk_8058920c);
// PAL: 0x80589230..0x80589254
UNKNOWN_FUNCTION(unk_80589230);
// PAL: 0x80589254..0x8058926c
UNKNOWN_FUNCTION(unk_80589254);
// PAL: 0x8058926c..0x80589308
UNKNOWN_FUNCTION(unk_8058926c);
// PAL: 0x80589308..0x805893fc
UNKNOWN_FUNCTION(unk_80589308);
// PAL: 0x805893fc..0x80589400
UNKNOWN_FUNCTION(unk_805893fc);
// PAL: 0x80589400..0x80589440
UNKNOWN_FUNCTION(PlayerSub10RealLocal_hop);
// PAL: 0x80589440..0x80589480
UNKNOWN_FUNCTION(PlayerSub10Bike_hop);
// PAL: 0x80589480..0x80589514
UNKNOWN_FUNCTION(unk_80589480);
// PAL: 0x80589514..0x8058956c
UNKNOWN_FUNCTION(unk_80589514);
// PAL: 0x8058956c..0x805895cc
UNKNOWN_FUNCTION(unk_8058956c);
// PAL: 0x805895cc..0x8058962c
UNKNOWN_FUNCTION(unk_805895cc);
// PAL: 0x8058962c..0x805896b8
UNKNOWN_FUNCTION(unk_8058962c);
// PAL: 0x805896b8..0x805896bc
UNKNOWN_FUNCTION(unk_805896b8);
// PAL: 0x805896bc..0x805896c4
UNKNOWN_FUNCTION(PlayerSub10Bike_getLeanRot);
// PAL: 0x805896c4..0x80589704
UNKNOWN_FUNCTION(unk_805896c4);
// PAL: 0x80589704..0x80589744
UNKNOWN_FUNCTION(PlayerSub10Bike_destroy);
// PAL: 0x80589744..0x8058974c
UNKNOWN_FUNCTION(PlayerSub10_checkWheelie);
// PAL: 0x8058974c..0x80589758
UNKNOWN_FUNCTION(PlayerSub10_getLeanRot);
// PAL: 0x80589758..0x80589798
UNKNOWN_FUNCTION(unk_80589758);
// PAL: 0x80589798..0x805897d8
UNKNOWN_FUNCTION(unk_80589798);
// PAL: 0x805897d8..0x80589818
UNKNOWN_FUNCTION(unk_805897d8);
// PAL: 0x80589818..0x80589830
UNKNOWN_FUNCTION(unk_80589818);
// PAL: 0x80589830..0x80589844
UNKNOWN_FUNCTION(unk_80589830);
// PAL: 0x80589844..0x8058985c
UNKNOWN_FUNCTION(unk_80589844);

#ifdef __cplusplus
}
#endif

namespace Kart {

// TODO: implement
class KartHalfPipe;
class KartJump;

class KartMove : public KartObjectProxy {
public:
  enum DrivingDirection {
    DRIVING_DIRECTION_IDLE = 2,
  };

  s16 getMaxMtCharge();
  s16 getMaxSmtCharge();
  s32 getAppliedHopStickX();
  void setScale(const EGG::Vector3f scale);
  void empty(s32 arg);
  void clearBoost();

  f32 baseSpeed() const { return mBaseSpeed; }
  f32 speed() const { return mSpeed; }
  f32 speedRatioCapped() const { return mSpeedRatioCapped; }
  f32 speedRatio() const { return mSpeedRatio; }
  s32 hopStickX() const { return mHopStickX; }
  s16 driftState() const { return mDriftState; }
  s16 mtCharge() const { return mMtCharge; }
  s16 smtCharge() const { return mSmtCharge; }
  const EGG::Vector3f& scale() const { return mScale; }
  s16 someTimer() const { return _someTimer; }
  s16 respawnTimer() const { return mRespawnTimer; }
  DrivingDirection drivingDirection() const { return mDrivingDirection; }
  s16 backwardsAllowCounter() const { return mBackwardsAllowCounter; }
  u16 flags() const { return mFlags; }
  const KartJump* kartJump() { return mJump; }
  const KartHalfPipe* kartHalfPipe() { return mHalfPipe; }

  void setScaledStartBoostCharge(f32 charge) {
    mScaledStartBoostCharge = charge;
  }

private:
  u8 _00c[0x014 - 0x00c];
  f32 mBaseSpeed;
  u8 _018[0x020 - 0x018];
  f32 mSpeed;
  u8 _024[0x0b0 - 0x024];
  f32 mSpeedRatioCapped;
  f32 mSpeedRatio;
  u8 _0b8[0x0cc - 0x0b8];
  s32 mHopStickX;
  u8 _0d0[0x0fc - 0x0d0];
  s16 mDriftState;
  s16 mMtCharge;
  s16 mSmtCharge;
  u8 _102[0x164 - 0x102];
  EGG::Vector3f mScale;
  u8 _170[0x224 - 0x170];
  f32 mScaledStartBoostCharge;
  u8 _228[0x238 - 0x228];
  s16 _someTimer;
  s16 mRespawnTimer;
  u8 _23c[0x248 - 0x23c];
  DrivingDirection mDrivingDirection;
  s16 mBackwardsAllowCounter;
  u8 _24e[0x254 - 0x24e];
  // TODO
  u16 mFlags;
  u8 _256[0x258 - 0x256];
  KartJump* mJump;
  KartHalfPipe* mHalfPipe;
  u8 _260[0x294 - 0x260];
};
static_assert(sizeof(KartMove) == 0x294);

} // namespace Kart
