#include "Section.hpp"

#include "SectionAutogens.hpp"

// --- EXTERN DECLARATIONS BEGIN ---

extern "C" {

// Extern function references.
// PAL: 0x80021594
extern UNKNOWN_FUNCTION(_savegpr_24);
// PAL: 0x800215e0
extern UNKNOWN_FUNCTION(_restgpr_24);
// PAL: 0x80082620
extern UNKNOWN_FUNCTION(unk_80082620);
// PAL: 0x800826a0
extern UNKNOWN_FUNCTION(unk_800826a0);
// PAL: 0x8016f3b8
extern UNKNOWN_FUNCTION(GXSetCullMode);
// PAL: 0x801720c0
extern UNKNOWN_FUNCTION(GXSetZTexture);
// PAL: 0x80172824
extern UNKNOWN_FUNCTION(GXSetZMode);
// PAL: 0x80172858
extern UNKNOWN_FUNCTION(GXSetZCompLoc);
// PAL: 0x80199d04
extern UNKNOWN_FUNCTION(PSMTXIdentity);
// PAL: 0x8020f62c
extern UNKNOWN_FUNCTION(__ct__Q23EGG9AllocatorFPQ23EGG4Heapl);
// PAL: 0x80229dcc
extern UNKNOWN_FUNCTION(__nw__FUl);
// PAL: 0x80229e14
extern UNKNOWN_FUNCTION(getGameScene);
// PAL: 0x805bac90
extern UNKNOWN_FUNCTION(unk_805bac90);
// PAL: 0x805bae98
extern UNKNOWN_FUNCTION(unk_805bae98);
// PAL: 0x805bb2c4
extern UNKNOWN_FUNCTION(unk_805bb2c4);
// PAL: 0x805bc03c
extern UNKNOWN_FUNCTION(unk_805bc03c);
// PAL: 0x805be66c
extern UNKNOWN_FUNCTION(unk_805be66c);
// PAL: 0x805bee4c
extern UNKNOWN_FUNCTION(unk_805bee4c);
// PAL: 0x805bff18
extern UNKNOWN_FUNCTION(ChannelPage_construct);
// PAL: 0x805c0cc8
extern UNKNOWN_FUNCTION(unk_805c0cc8);
// PAL: 0x805c13ac
extern UNKNOWN_FUNCTION(unk_805c13ac);
// PAL: 0x805c1cc0
extern UNKNOWN_FUNCTION(ConfirmPage_ct);
// PAL: 0x805c35f8
extern UNKNOWN_FUNCTION(unk_805c35f8);
// PAL: 0x805c37e0
extern UNKNOWN_FUNCTION(ControllerBatteryPage_construct);
// PAL: 0x805c4768
extern UNKNOWN_FUNCTION(unk_805c4768);
// PAL: 0x805c57b0
extern UNKNOWN_FUNCTION(unk_805c57b0);
// PAL: 0x805c6c78
extern UNKNOWN_FUNCTION(ChannelGhostSelectPage_ct);
// PAL: 0x805c8490
extern UNKNOWN_FUNCTION(unk_805c8490);
// PAL: 0x805c9774
extern UNKNOWN_FUNCTION(unk_805c9774);
// PAL: 0x805cafd8
extern UNKNOWN_FUNCTION(unk_805cafd8);
// PAL: 0x805cbd88
extern UNKNOWN_FUNCTION(unk_805cbd88);
// PAL: 0x805cc3b8
extern UNKNOWN_FUNCTION(unk_805cc3b8);
// PAL: 0x805cdac0
extern UNKNOWN_FUNCTION(unk_805cdac0);
// PAL: 0x805cdb68
extern UNKNOWN_FUNCTION(unk_805cdb68);
// PAL: 0x805d1ab8
extern UNKNOWN_FUNCTION(unk_805d1ab8);
// PAL: 0x805d1e84
extern UNKNOWN_FUNCTION(unk_805d1e84);
// PAL: 0x805d2040
extern UNKNOWN_FUNCTION(unk_805d2040);
// PAL: 0x805d20a4
extern UNKNOWN_FUNCTION(unk_805d20a4);
// PAL: 0x805d2264
extern UNKNOWN_FUNCTION(unk_805d2264);
// PAL: 0x805d41c8
extern UNKNOWN_FUNCTION(FriendListPage_construct);
// PAL: 0x805d585c
extern UNKNOWN_FUNCTION(FriendSelectPage_construct);
// PAL: 0x805d69ac
extern UNKNOWN_FUNCTION(FriendDeletePage_construct);
// PAL: 0x805d7204
extern UNKNOWN_FUNCTION(unk_805d7204);
// PAL: 0x805d796c
extern UNKNOWN_FUNCTION(unk_805d796c);
// PAL: 0x805d7f78
extern UNKNOWN_FUNCTION(FriendRoomPage_construct);
// PAL: 0x805d9b38
extern UNKNOWN_FUNCTION(FriendRoomBusyPage_construct);
// PAL: 0x805dbd94
extern UNKNOWN_FUNCTION(FriendRoomMessageSelectPage_construct);
// PAL: 0x805dd330
extern UNKNOWN_FUNCTION(FriendMatchingPage_construct);
// PAL: 0x805de9f0
extern UNKNOWN_FUNCTION(unk_805de9f0);
// PAL: 0x805defd4
extern UNKNOWN_FUNCTION(unk_805defd4);
// PAL: 0x805e0584
extern UNKNOWN_FUNCTION(unk_805e0584);
// PAL: 0x805e0c38
extern UNKNOWN_FUNCTION(GhostManagerPage_construct);
// PAL: 0x805e422c
extern UNKNOWN_FUNCTION(GlobePage_construct);
// PAL: 0x805e6b50
extern UNKNOWN_FUNCTION(unk_805e6b50);
// PAL: 0x805e9eec
extern UNKNOWN_FUNCTION(LayoutThing3List_construct);
// PAL: 0x805e9ef8
extern UNKNOWN_FUNCTION(LayoutThing3List_destroy);
// PAL: 0x805ea28c
extern UNKNOWN_FUNCTION(UIResourceAccessorList_construct);
// PAL: 0x805ea298
extern UNKNOWN_FUNCTION(UIResourceAccessorList_destroy);
// PAL: 0x805ea834
extern UNKNOWN_FUNCTION(LicenseSelectPage_construct);
// PAL: 0x805ebdac
extern UNKNOWN_FUNCTION(LicenseDisplayPage_construct);
// PAL: 0x805ed4ec
extern UNKNOWN_FUNCTION(LicenseManagementPage_construct);
// PAL: 0x805eddf4
extern UNKNOWN_FUNCTION(LicenseDeletePage_ct);
// PAL: 0x805f4fd0
extern UNKNOWN_FUNCTION(unk_805f4fd0);
// PAL: 0x805f8fac
extern UNKNOWN_FUNCTION(MessageWindowPopupPage_ct);
// PAL: 0x805f931c
extern UNKNOWN_FUNCTION(unk_805f931c);
// PAL: 0x805fb5bc
extern UNKNOWN_FUNCTION(unk_805fb5bc);
// PAL: 0x805fcd40
extern UNKNOWN_FUNCTION(unk_805fcd40);
// PAL: 0x805fcd90
extern UNKNOWN_FUNCTION(unk_805fcd90);
// PAL: 0x805fcde8
extern UNKNOWN_FUNCTION(thunk_unk_80529c40);
// PAL: 0x805fcdec
extern UNKNOWN_FUNCTION(unk_805fcdec);
// PAL: 0x805fce7c
extern UNKNOWN_FUNCTION(unk_805fce7c);
// PAL: 0x805fd438
extern UNKNOWN_FUNCTION(unk_805fd438);
// PAL: 0x805fd454
extern UNKNOWN_FUNCTION(unk_805fd454);
// PAL: 0x805fd518
extern UNKNOWN_FUNCTION(OptionsPage_ct);
// PAL: 0x805fdaa8
extern UNKNOWN_FUNCTION(unk_805fdaa8);
// PAL: 0x805fe128
extern UNKNOWN_FUNCTION(unk_805fe128);
// PAL: 0x805fe5f8
extern UNKNOWN_FUNCTION(OptionMessageWindowPage_ct);
// PAL: 0x805feda4
extern UNKNOWN_FUNCTION(unk_805feda4);
// PAL: 0x805ff328
extern UNKNOWN_FUNCTION(unk_805ff328);
// PAL: 0x80601a60
extern UNKNOWN_FUNCTION(Page_init);
// PAL: 0x80601adc
extern UNKNOWN_FUNCTION(Page_fini);
// PAL: 0x80601aec
extern UNKNOWN_FUNCTION(Page_activate);
// PAL: 0x80601c08
extern UNKNOWN_FUNCTION(Page_deactivate);
// PAL: 0x80601c48
extern UNKNOWN_FUNCTION(unk_80601c48);
// PAL: 0x80601c64
extern UNKNOWN_FUNCTION(unk_80601c64);
// PAL: 0x80601d24
extern UNKNOWN_FUNCTION(unk_80601d24);
// PAL: 0x80601f44
extern UNKNOWN_FUNCTION(unk_80601f44);
// PAL: 0x806022cc
extern UNKNOWN_FUNCTION(Page_calc);
// PAL: 0x80602338
extern UNKNOWN_FUNCTION(unk_80602338);
// PAL: 0x8060235c
extern UNKNOWN_FUNCTION(draw__Q22UI4PageFUl);
// PAL: 0x80602378
extern UNKNOWN_FUNCTION(unk_80602378);
// PAL: 0x8060238c
extern UNKNOWN_FUNCTION(unk_8060238c);
// PAL: 0x80602390
extern UNKNOWN_FUNCTION(Page_refocus);
// PAL: 0x80602428
extern UNKNOWN_FUNCTION(unk_80602428);
// PAL: 0x8060244c
extern UNKNOWN_FUNCTION(setAnimationDirection__Q22UI4PageFl);
// PAL: 0x80602e54
extern UNKNOWN_FUNCTION(SystemPage_init);
// PAL: 0x80602f04
extern UNKNOWN_FUNCTION(unk_80602f04);
// PAL: 0x80603764
extern UNKNOWN_FUNCTION(unk_80603764);
// PAL: 0x80604584
extern UNKNOWN_FUNCTION(unk_80604584);
// PAL: 0x80604cd8
extern UNKNOWN_FUNCTION(unk_80604cd8);
// PAL: 0x80608060
extern UNKNOWN_FUNCTION(unk_80608060);
// PAL: 0x8060ad38
extern UNKNOWN_FUNCTION(RankingDetailPage_ct);
// PAL: 0x8060bd28
extern UNKNOWN_FUNCTION(RankingTopTenDownloadPage_ct);
// PAL: 0x8060d294
extern UNKNOWN_FUNCTION(unk_8060d294);
// PAL: 0x8060dc20
extern UNKNOWN_FUNCTION(ChannelGhostPage_ct);
// PAL: 0x80615044
extern UNKNOWN_FUNCTION(RankingBackPage_construct);
// PAL: 0x806153b4
extern UNKNOWN_FUNCTION(RankingPage_construct);
// PAL: 0x8061bd14
extern UNKNOWN_FUNCTION(unk_8061bd14);
// PAL: 0x8061d214
extern UNKNOWN_FUNCTION(unk_8061d214);
// PAL: 0x8061dcb8
extern UNKNOWN_FUNCTION(unk_8061dcb8);
// PAL: 0x8061e898
extern UNKNOWN_FUNCTION(unk_8061e898);
// PAL: 0x8061f6e8
extern UNKNOWN_FUNCTION(unk_8061f6e8);
// PAL: 0x806200bc
extern UNKNOWN_FUNCTION(unk_806200bc);
// PAL: 0x80620440
extern UNKNOWN_FUNCTION(unk_80620440);
// PAL: 0x80620638
extern UNKNOWN_FUNCTION(unk_80620638);
// PAL: 0x80623068
extern UNKNOWN_FUNCTION(Section_calcActivation);
// PAL: 0x80623390
extern UNKNOWN_FUNCTION(Section_createPage);
// PAL: 0x806233bc
extern UNKNOWN_FUNCTION(jump_806233bc);
// PAL: 0x806233d4
extern UNKNOWN_FUNCTION(jump_806233d4);
// PAL: 0x806233ec
extern UNKNOWN_FUNCTION(jump_806233ec);
// PAL: 0x80623404
extern UNKNOWN_FUNCTION(jump_80623404);
// PAL: 0x8062341c
extern UNKNOWN_FUNCTION(jump_8062341c);
// PAL: 0x80623434
extern UNKNOWN_FUNCTION(jump_80623434);
// PAL: 0x8062344c
extern UNKNOWN_FUNCTION(jump_8062344c);
// PAL: 0x80623464
extern UNKNOWN_FUNCTION(jump_80623464);
// PAL: 0x8062347c
extern UNKNOWN_FUNCTION(jump_8062347c);
// PAL: 0x80623494
extern UNKNOWN_FUNCTION(jump_80623494);
// PAL: 0x806234ac
extern UNKNOWN_FUNCTION(jump_806234ac);
// PAL: 0x806234c4
extern UNKNOWN_FUNCTION(jump_806234c4);
// PAL: 0x806234dc
extern UNKNOWN_FUNCTION(jump_806234dc);
// PAL: 0x806234f4
extern UNKNOWN_FUNCTION(jump_806234f4);
// PAL: 0x8062350c
extern UNKNOWN_FUNCTION(jump_8062350c);
// PAL: 0x80623524
extern UNKNOWN_FUNCTION(jump_80623524);
// PAL: 0x8062353c
extern UNKNOWN_FUNCTION(jump_8062353c);
// PAL: 0x80623554
extern UNKNOWN_FUNCTION(jump_80623554);
// PAL: 0x8062356c
extern UNKNOWN_FUNCTION(jump_8062356c);
// PAL: 0x80623584
extern UNKNOWN_FUNCTION(jump_80623584);
// PAL: 0x8062359c
extern UNKNOWN_FUNCTION(jump_8062359c);
// PAL: 0x806235b4
extern UNKNOWN_FUNCTION(jump_806235b4);
// PAL: 0x806235cc
extern UNKNOWN_FUNCTION(jump_806235cc);
// PAL: 0x806235e4
extern UNKNOWN_FUNCTION(jump_806235e4);
// PAL: 0x806235fc
extern UNKNOWN_FUNCTION(jump_806235fc);
// PAL: 0x80623614
extern UNKNOWN_FUNCTION(jump_80623614);
// PAL: 0x8062362c
extern UNKNOWN_FUNCTION(jump_8062362c);
// PAL: 0x80623644
extern UNKNOWN_FUNCTION(jump_80623644);
// PAL: 0x8062365c
extern UNKNOWN_FUNCTION(jump_8062365c);
// PAL: 0x80623674
extern UNKNOWN_FUNCTION(jump_80623674);
// PAL: 0x8062368c
extern UNKNOWN_FUNCTION(jump_8062368c);
// PAL: 0x806236a4
extern UNKNOWN_FUNCTION(jump_806236a4);
// PAL: 0x806236bc
extern UNKNOWN_FUNCTION(jump_806236bc);
// PAL: 0x806236d4
extern UNKNOWN_FUNCTION(jump_806236d4);
// PAL: 0x806236ec
extern UNKNOWN_FUNCTION(jump_806236ec);
// PAL: 0x80623704
extern UNKNOWN_FUNCTION(jump_80623704);
// PAL: 0x8062371c
extern UNKNOWN_FUNCTION(jump_8062371c);
// PAL: 0x80623734
extern UNKNOWN_FUNCTION(jump_80623734);
// PAL: 0x8062374c
extern UNKNOWN_FUNCTION(jump_8062374c);
// PAL: 0x80623764
extern UNKNOWN_FUNCTION(jump_80623764);
// PAL: 0x8062377c
extern UNKNOWN_FUNCTION(jump_8062377c);
// PAL: 0x80623794
extern UNKNOWN_FUNCTION(jump_80623794);
// PAL: 0x806237ac
extern UNKNOWN_FUNCTION(jump_806237ac);
// PAL: 0x806237c4
extern UNKNOWN_FUNCTION(jump_806237c4);
// PAL: 0x806237dc
extern UNKNOWN_FUNCTION(jump_806237dc);
// PAL: 0x806237f4
extern UNKNOWN_FUNCTION(jump_806237f4);
// PAL: 0x8062380c
extern UNKNOWN_FUNCTION(jump_8062380c);
// PAL: 0x80623824
extern UNKNOWN_FUNCTION(jump_80623824);
// PAL: 0x8062383c
extern UNKNOWN_FUNCTION(jump_8062383c);
// PAL: 0x80623854
extern UNKNOWN_FUNCTION(jump_80623854);
// PAL: 0x8062386c
extern UNKNOWN_FUNCTION(jump_8062386c);
// PAL: 0x80623884
extern UNKNOWN_FUNCTION(jump_80623884);
// PAL: 0x8062389c
extern UNKNOWN_FUNCTION(jump_8062389c);
// PAL: 0x806238b4
extern UNKNOWN_FUNCTION(jump_806238b4);
// PAL: 0x806238cc
extern UNKNOWN_FUNCTION(jump_806238cc);
// PAL: 0x806238e4
extern UNKNOWN_FUNCTION(jump_806238e4);
// PAL: 0x806238fc
extern UNKNOWN_FUNCTION(jump_806238fc);
// PAL: 0x80623914
extern UNKNOWN_FUNCTION(jump_80623914);
// PAL: 0x8062392c
extern UNKNOWN_FUNCTION(jump_8062392c);
// PAL: 0x80623944
extern UNKNOWN_FUNCTION(jump_80623944);
// PAL: 0x8062395c
extern UNKNOWN_FUNCTION(jump_8062395c);
// PAL: 0x80623974
extern UNKNOWN_FUNCTION(jump_80623974);
// PAL: 0x8062398c
extern UNKNOWN_FUNCTION(jump_8062398c);
// PAL: 0x806239a4
extern UNKNOWN_FUNCTION(jump_806239a4);
// PAL: 0x806239bc
extern UNKNOWN_FUNCTION(jump_806239bc);
// PAL: 0x806239d4
extern UNKNOWN_FUNCTION(jump_806239d4);
// PAL: 0x806239ec
extern UNKNOWN_FUNCTION(jump_806239ec);
// PAL: 0x80623a04
extern UNKNOWN_FUNCTION(jump_80623a04);
// PAL: 0x80623a1c
extern UNKNOWN_FUNCTION(jump_80623a1c);
// PAL: 0x80623a34
extern UNKNOWN_FUNCTION(jump_80623a34);
// PAL: 0x80623a4c
extern UNKNOWN_FUNCTION(jump_80623a4c);
// PAL: 0x80623a64
extern UNKNOWN_FUNCTION(jump_80623a64);
// PAL: 0x80623a7c
extern UNKNOWN_FUNCTION(jump_80623a7c);
// PAL: 0x80623a94
extern UNKNOWN_FUNCTION(jump_80623a94);
// PAL: 0x80623aac
extern UNKNOWN_FUNCTION(jump_80623aac);
// PAL: 0x80623ac4
extern UNKNOWN_FUNCTION(jump_80623ac4);
// PAL: 0x80623adc
extern UNKNOWN_FUNCTION(jump_80623adc);
// PAL: 0x80623af4
extern UNKNOWN_FUNCTION(jump_80623af4);
// PAL: 0x80623b0c
extern UNKNOWN_FUNCTION(jump_80623b0c);
// PAL: 0x80623b24
extern UNKNOWN_FUNCTION(jump_80623b24);
// PAL: 0x80623b3c
extern UNKNOWN_FUNCTION(jump_80623b3c);
// PAL: 0x80623b54
extern UNKNOWN_FUNCTION(jump_80623b54);
// PAL: 0x80623b6c
extern UNKNOWN_FUNCTION(jump_80623b6c);
// PAL: 0x80623b84
extern UNKNOWN_FUNCTION(jump_80623b84);
// PAL: 0x80623b9c
extern UNKNOWN_FUNCTION(jump_80623b9c);
// PAL: 0x80623bb4
extern UNKNOWN_FUNCTION(jump_80623bb4);
// PAL: 0x80623bcc
extern UNKNOWN_FUNCTION(jump_80623bcc);
// PAL: 0x80623be4
extern UNKNOWN_FUNCTION(jump_80623be4);
// PAL: 0x80623bfc
extern UNKNOWN_FUNCTION(jump_80623bfc);
// PAL: 0x80623c14
extern UNKNOWN_FUNCTION(jump_80623c14);
// PAL: 0x80623c2c
extern UNKNOWN_FUNCTION(jump_80623c2c);
// PAL: 0x80623c44
extern UNKNOWN_FUNCTION(jump_80623c44);
// PAL: 0x80623c5c
extern UNKNOWN_FUNCTION(jump_80623c5c);
// PAL: 0x80623c74
extern UNKNOWN_FUNCTION(jump_80623c74);
// PAL: 0x80623c8c
extern UNKNOWN_FUNCTION(jump_80623c8c);
// PAL: 0x80623ca4
extern UNKNOWN_FUNCTION(jump_80623ca4);
// PAL: 0x80623cbc
extern UNKNOWN_FUNCTION(jump_80623cbc);
// PAL: 0x80623cd4
extern UNKNOWN_FUNCTION(jump_80623cd4);
// PAL: 0x80623cec
extern UNKNOWN_FUNCTION(jump_80623cec);
// PAL: 0x80623d04
extern UNKNOWN_FUNCTION(jump_80623d04);
// PAL: 0x80623d1c
extern UNKNOWN_FUNCTION(jump_80623d1c);
// PAL: 0x80623d34
extern UNKNOWN_FUNCTION(jump_80623d34);
// PAL: 0x80623d4c
extern UNKNOWN_FUNCTION(jump_80623d4c);
// PAL: 0x80623d64
extern UNKNOWN_FUNCTION(jump_80623d64);
// PAL: 0x80623d7c
extern UNKNOWN_FUNCTION(jump_80623d7c);
// PAL: 0x80623d94
extern UNKNOWN_FUNCTION(jump_80623d94);
// PAL: 0x80623dac
extern UNKNOWN_FUNCTION(jump_80623dac);
// PAL: 0x80623dc4
extern UNKNOWN_FUNCTION(jump_80623dc4);
// PAL: 0x80623ddc
extern UNKNOWN_FUNCTION(jump_80623ddc);
// PAL: 0x80623df4
extern UNKNOWN_FUNCTION(jump_80623df4);
// PAL: 0x80623e0c
extern UNKNOWN_FUNCTION(jump_80623e0c);
// PAL: 0x80623e24
extern UNKNOWN_FUNCTION(jump_80623e24);
// PAL: 0x80623e3c
extern UNKNOWN_FUNCTION(jump_80623e3c);
// PAL: 0x80623e54
extern UNKNOWN_FUNCTION(jump_80623e54);
// PAL: 0x80623e6c
extern UNKNOWN_FUNCTION(jump_80623e6c);
// PAL: 0x80623e84
extern UNKNOWN_FUNCTION(jump_80623e84);
// PAL: 0x80623e9c
extern UNKNOWN_FUNCTION(jump_80623e9c);
// PAL: 0x80623eb4
extern UNKNOWN_FUNCTION(jump_80623eb4);
// PAL: 0x80623ecc
extern UNKNOWN_FUNCTION(jump_80623ecc);
// PAL: 0x80623ee4
extern UNKNOWN_FUNCTION(jump_80623ee4);
// PAL: 0x80623efc
extern UNKNOWN_FUNCTION(jump_80623efc);
// PAL: 0x80623f14
extern UNKNOWN_FUNCTION(jump_80623f14);
// PAL: 0x80623f2c
extern UNKNOWN_FUNCTION(jump_80623f2c);
// PAL: 0x80623f44
extern UNKNOWN_FUNCTION(jump_80623f44);
// PAL: 0x80623f5c
extern UNKNOWN_FUNCTION(jump_80623f5c);
// PAL: 0x80623f74
extern UNKNOWN_FUNCTION(jump_80623f74);
// PAL: 0x80623f8c
extern UNKNOWN_FUNCTION(jump_80623f8c);
// PAL: 0x80623fa4
extern UNKNOWN_FUNCTION(jump_80623fa4);
// PAL: 0x80623fbc
extern UNKNOWN_FUNCTION(jump_80623fbc);
// PAL: 0x80623fd4
extern UNKNOWN_FUNCTION(jump_80623fd4);
// PAL: 0x80623fec
extern UNKNOWN_FUNCTION(jump_80623fec);
// PAL: 0x80624004
extern UNKNOWN_FUNCTION(jump_80624004);
// PAL: 0x8062401c
extern UNKNOWN_FUNCTION(jump_8062401c);
// PAL: 0x80624034
extern UNKNOWN_FUNCTION(jump_80624034);
// PAL: 0x8062404c
extern UNKNOWN_FUNCTION(jump_8062404c);
// PAL: 0x80624064
extern UNKNOWN_FUNCTION(jump_80624064);
// PAL: 0x8062407c
extern UNKNOWN_FUNCTION(jump_8062407c);
// PAL: 0x80624094
extern UNKNOWN_FUNCTION(jump_80624094);
// PAL: 0x806240ac
extern UNKNOWN_FUNCTION(jump_806240ac);
// PAL: 0x806240c4
extern UNKNOWN_FUNCTION(jump_806240c4);
// PAL: 0x806240dc
extern UNKNOWN_FUNCTION(jump_806240dc);
// PAL: 0x806240f4
extern UNKNOWN_FUNCTION(jump_806240f4);
// PAL: 0x8062410c
extern UNKNOWN_FUNCTION(jump_8062410c);
// PAL: 0x80624124
extern UNKNOWN_FUNCTION(jump_80624124);
// PAL: 0x8062413c
extern UNKNOWN_FUNCTION(jump_8062413c);
// PAL: 0x80624154
extern UNKNOWN_FUNCTION(jump_80624154);
// PAL: 0x8062416c
extern UNKNOWN_FUNCTION(jump_8062416c);
// PAL: 0x80624184
extern UNKNOWN_FUNCTION(jump_80624184);
// PAL: 0x8062419c
extern UNKNOWN_FUNCTION(jump_8062419c);
// PAL: 0x806241b4
extern UNKNOWN_FUNCTION(jump_806241b4);
// PAL: 0x806241cc
extern UNKNOWN_FUNCTION(jump_806241cc);
// PAL: 0x806241e4
extern UNKNOWN_FUNCTION(jump_806241e4);
// PAL: 0x806241fc
extern UNKNOWN_FUNCTION(jump_806241fc);
// PAL: 0x80624214
extern UNKNOWN_FUNCTION(jump_80624214);
// PAL: 0x8062422c
extern UNKNOWN_FUNCTION(jump_8062422c);
// PAL: 0x80624244
extern UNKNOWN_FUNCTION(jump_80624244);
// PAL: 0x8062425c
extern UNKNOWN_FUNCTION(jump_8062425c);
// PAL: 0x80624274
extern UNKNOWN_FUNCTION(jump_80624274);
// PAL: 0x8062428c
extern UNKNOWN_FUNCTION(jump_8062428c);
// PAL: 0x806242a4
extern UNKNOWN_FUNCTION(jump_806242a4);
// PAL: 0x806242bc
extern UNKNOWN_FUNCTION(jump_806242bc);
// PAL: 0x806242d4
extern UNKNOWN_FUNCTION(jump_806242d4);
// PAL: 0x806242ec
extern UNKNOWN_FUNCTION(jump_806242ec);
// PAL: 0x80624304
extern UNKNOWN_FUNCTION(jump_80624304);
// PAL: 0x8062431c
extern UNKNOWN_FUNCTION(jump_8062431c);
// PAL: 0x80624334
extern UNKNOWN_FUNCTION(jump_80624334);
// PAL: 0x8062434c
extern UNKNOWN_FUNCTION(jump_8062434c);
// PAL: 0x80624364
extern UNKNOWN_FUNCTION(jump_80624364);
// PAL: 0x8062437c
extern UNKNOWN_FUNCTION(jump_8062437c);
// PAL: 0x80624394
extern UNKNOWN_FUNCTION(jump_80624394);
// PAL: 0x806243ac
extern UNKNOWN_FUNCTION(jump_806243ac);
// PAL: 0x806243c4
extern UNKNOWN_FUNCTION(jump_806243c4);
// PAL: 0x806243dc
extern UNKNOWN_FUNCTION(jump_806243dc);
// PAL: 0x806243f4
extern UNKNOWN_FUNCTION(jump_806243f4);
// PAL: 0x8062440c
extern UNKNOWN_FUNCTION(jump_8062440c);
// PAL: 0x80624424
extern UNKNOWN_FUNCTION(jump_80624424);
// PAL: 0x8062443c
extern UNKNOWN_FUNCTION(jump_8062443c);
// PAL: 0x80624454
extern UNKNOWN_FUNCTION(jump_80624454);
// PAL: 0x8062446c
extern UNKNOWN_FUNCTION(jump_8062446c);
// PAL: 0x80624484
extern UNKNOWN_FUNCTION(jump_80624484);
// PAL: 0x8062449c
extern UNKNOWN_FUNCTION(jump_8062449c);
// PAL: 0x806244b4
extern UNKNOWN_FUNCTION(jump_806244b4);
// PAL: 0x806244cc
extern UNKNOWN_FUNCTION(jump_806244cc);
// PAL: 0x806244e4
extern UNKNOWN_FUNCTION(jump_806244e4);
// PAL: 0x806244fc
extern UNKNOWN_FUNCTION(jump_806244fc);
// PAL: 0x80624514
extern UNKNOWN_FUNCTION(jump_80624514);
// PAL: 0x8062452c
extern UNKNOWN_FUNCTION(jump_8062452c);
// PAL: 0x80624544
extern UNKNOWN_FUNCTION(jump_80624544);
// PAL: 0x8062455c
extern UNKNOWN_FUNCTION(jump_8062455c);
// PAL: 0x80624574
extern UNKNOWN_FUNCTION(jump_80624574);
// PAL: 0x8062458c
extern UNKNOWN_FUNCTION(jump_8062458c);
// PAL: 0x806245a4
extern UNKNOWN_FUNCTION(jump_806245a4);
// PAL: 0x806245bc
extern UNKNOWN_FUNCTION(jump_806245bc);
// PAL: 0x806245d4
extern UNKNOWN_FUNCTION(jump_806245d4);
// PAL: 0x806245ec
extern UNKNOWN_FUNCTION(jump_806245ec);
// PAL: 0x80624604
extern UNKNOWN_FUNCTION(jump_80624604);
// PAL: 0x8062461c
extern UNKNOWN_FUNCTION(jump_8062461c);
// PAL: 0x80624634
extern UNKNOWN_FUNCTION(jump_80624634);
// PAL: 0x8062464c
extern UNKNOWN_FUNCTION(jump_8062464c);
// PAL: 0x80624664
extern UNKNOWN_FUNCTION(jump_80624664);
// PAL: 0x80624690
extern UNKNOWN_FUNCTION(unk_80624690);
// PAL: 0x806246e4
extern UNKNOWN_FUNCTION(GpRacePage_construct);
// PAL: 0x806247cc
extern UNKNOWN_FUNCTION(TtRacePage_construct);
// PAL: 0x80624874
extern UNKNOWN_FUNCTION(unk_80624874);
// PAL: 0x806248f4
extern UNKNOWN_FUNCTION(unk_806248f4);
// PAL: 0x80624974
extern UNKNOWN_FUNCTION(unk_80624974);
// PAL: 0x806249f4
extern UNKNOWN_FUNCTION(unk_806249f4);
// PAL: 0x80624a74
extern UNKNOWN_FUNCTION(unk_80624a74);
// PAL: 0x80624af4
extern UNKNOWN_FUNCTION(unk_80624af4);
// PAL: 0x80624ba0
extern UNKNOWN_FUNCTION(unk_80624ba0);
// PAL: 0x80624be4
extern UNKNOWN_FUNCTION(unk_80624be4);
// PAL: 0x80624c28
extern UNKNOWN_FUNCTION(unk_80624c28);
// PAL: 0x80624c6c
extern UNKNOWN_FUNCTION(unk_80624c6c);
// PAL: 0x80624cb0
extern UNKNOWN_FUNCTION(unk_80624cb0);
// PAL: 0x80624cf4
extern UNKNOWN_FUNCTION(unk_80624cf4);
// PAL: 0x80624d38
extern UNKNOWN_FUNCTION(unk_80624d38);
// PAL: 0x80624d7c
extern UNKNOWN_FUNCTION(unk_80624d7c);
// PAL: 0x80624dc0
extern UNKNOWN_FUNCTION(unk_80624dc0);
// PAL: 0x80624e04
extern UNKNOWN_FUNCTION(unk_80624e04);
// PAL: 0x80624e48
extern UNKNOWN_FUNCTION(unk_80624e48);
// PAL: 0x80624e8c
extern UNKNOWN_FUNCTION(unk_80624e8c);
// PAL: 0x80624ed0
extern UNKNOWN_FUNCTION(unk_80624ed0);
// PAL: 0x80624f14
extern UNKNOWN_FUNCTION(unk_80624f14);
// PAL: 0x80624f58
extern UNKNOWN_FUNCTION(unk_80624f58);
// PAL: 0x80624f9c
extern UNKNOWN_FUNCTION(unk_80624f9c);
// PAL: 0x80624fe0
extern UNKNOWN_FUNCTION(unk_80624fe0);
// PAL: 0x80625024
extern UNKNOWN_FUNCTION(unk_80625024);
// PAL: 0x80625068
extern UNKNOWN_FUNCTION(unk_80625068);
// PAL: 0x806250ac
extern UNKNOWN_FUNCTION(unk_806250ac);
// PAL: 0x806250f0
extern UNKNOWN_FUNCTION(unk_806250f0);
// PAL: 0x80625134
extern UNKNOWN_FUNCTION(TimeAttackLeaderboardPage_ct);
// PAL: 0x8062526c
extern UNKNOWN_FUNCTION(unk_8062526c);
// PAL: 0x806252a8
extern UNKNOWN_FUNCTION(unk_806252a8);
// PAL: 0x806252e4
extern UNKNOWN_FUNCTION(unk_806252e4);
// PAL: 0x80625320
extern UNKNOWN_FUNCTION(unk_80625320);
// PAL: 0x806254e8
extern UNKNOWN_FUNCTION(unk_806254e8);
// PAL: 0x80625550
extern UNKNOWN_FUNCTION(unk_80625550);
// PAL: 0x806255b8
extern UNKNOWN_FUNCTION(unk_806255b8);
// PAL: 0x806255f4
extern UNKNOWN_FUNCTION(unk_806255f4);
// PAL: 0x80625674
extern UNKNOWN_FUNCTION(unk_80625674);
// PAL: 0x806256f4
extern UNKNOWN_FUNCTION(unk_806256f4);
// PAL: 0x80625738
extern UNKNOWN_FUNCTION(unk_80625738);
// PAL: 0x8062577c
extern UNKNOWN_FUNCTION(unk_8062577c);
// PAL: 0x806257fc
extern UNKNOWN_FUNCTION(unk_806257fc);
// PAL: 0x8062587c
extern UNKNOWN_FUNCTION(unk_8062587c);
// PAL: 0x806258fc
extern UNKNOWN_FUNCTION(unk_806258fc);
// PAL: 0x8062597c
extern UNKNOWN_FUNCTION(LiveViewPage_ct);
// PAL: 0x806259fc
extern UNKNOWN_FUNCTION(unk_806259fc);
// PAL: 0x80625a7c
extern UNKNOWN_FUNCTION(RaceConfirmPage_ct);
// PAL: 0x80625da0
extern UNKNOWN_FUNCTION(MainMenuPage_ct);
// PAL: 0x80626078
extern UNKNOWN_FUNCTION(unk_80626078);
// PAL: 0x806261e8
extern UNKNOWN_FUNCTION(unk_806261e8);
// PAL: 0x8062635c
extern UNKNOWN_FUNCTION(MiiSelectPage_ct);
// PAL: 0x80626698
extern UNKNOWN_FUNCTION(SingleMenuPage_ct);
// PAL: 0x80626950
extern UNKNOWN_FUNCTION(ClassSelectPage_ct);
// PAL: 0x80626c10
extern UNKNOWN_FUNCTION(CharacterSelectPage_construct);
// PAL: 0x80627060
extern UNKNOWN_FUNCTION(VehicleSelectPage_ct);
// PAL: 0x806273cc
extern UNKNOWN_FUNCTION(DriftSelectPage_ct);
// PAL: 0x80627684
extern UNKNOWN_FUNCTION(RaceCupSelectPage_construct);
// PAL: 0x80627bd8
extern UNKNOWN_FUNCTION(RaceCourseSelectPage_construct);
// PAL: 0x80628210
extern UNKNOWN_FUNCTION(VsMenuPage_ct);
// PAL: 0x806284c8
extern UNKNOWN_FUNCTION(VsSettingsPage_ct);
// PAL: 0x806287e0
extern UNKNOWN_FUNCTION(unk_806287e0);
// PAL: 0x80628b84
extern UNKNOWN_FUNCTION(unk_80628b84);
// PAL: 0x80628e3c
extern UNKNOWN_FUNCTION(unk_80628e3c);
// PAL: 0x80629184
extern UNKNOWN_FUNCTION(unk_80629184);
// PAL: 0x8062949c
extern UNKNOWN_FUNCTION(unk_8062949c);
// PAL: 0x80629954
extern UNKNOWN_FUNCTION(unk_80629954);
// PAL: 0x80629f30
extern UNKNOWN_FUNCTION(unk_80629f30);
// PAL: 0x8062a3e8
extern UNKNOWN_FUNCTION(unk_8062a3e8);
// PAL: 0x8062a9c4
extern UNKNOWN_FUNCTION(unk_8062a9c4);
// PAL: 0x8062ac9c
extern UNKNOWN_FUNCTION(unk_8062ac9c);
// PAL: 0x8062af88
extern UNKNOWN_FUNCTION(unk_8062af88);
// PAL: 0x8062b240
extern UNKNOWN_FUNCTION(unk_8062b240);
// PAL: 0x8062b4f4
extern UNKNOWN_FUNCTION(unk_8062b4f4);
// PAL: 0x8062b8bc
extern UNKNOWN_FUNCTION(unk_8062b8bc);
// PAL: 0x8062bb70
extern UNKNOWN_FUNCTION(unk_8062bb70);
// PAL: 0x8062be24
extern UNKNOWN_FUNCTION(unk_8062be24);
// PAL: 0x8062c0f4
extern UNKNOWN_FUNCTION(RecordsPage_ct);
// PAL: 0x8062c3a4
extern UNKNOWN_FUNCTION(Section_addPages);
// PAL: 0x80630094
extern UNKNOWN_FUNCTION(Section_addActivePages);
// PAL: 0x80634a64
extern UNKNOWN_FUNCTION(createSystemPage);
// PAL: 0x80637514
extern UNKNOWN_FUNCTION(EsrbPage_construct);
// PAL: 0x806376e8
extern UNKNOWN_FUNCTION(Pal60Page_construct);
// PAL: 0x80638e88
extern UNKNOWN_FUNCTION(TimeAttackBackPage_ct);
// PAL: 0x806395ec
extern UNKNOWN_FUNCTION(GhostSelectPage_ct);
// PAL: 0x8063aa08
extern UNKNOWN_FUNCTION(TitlePage_construct);
// PAL: 0x8063b514
extern UNKNOWN_FUNCTION(TitleBackPage_construct);
// PAL: 0x8063bb08
extern UNKNOWN_FUNCTION(TitleMoviePage_construct);
// PAL: 0x8063c0ac
extern UNKNOWN_FUNCTION(unk_8063c0ac);
// PAL: 0x80642f90
extern UNKNOWN_FUNCTION(unk_80642f90);
// PAL: 0x806446b8
extern UNKNOWN_FUNCTION(unk_806446b8);
// PAL: 0x806449f8
extern UNKNOWN_FUNCTION(unk_806449f8);
// PAL: 0x80645bc8
extern UNKNOWN_FUNCTION(unk_80645bc8);
// PAL: 0x806467d4
extern UNKNOWN_FUNCTION(unk_806467d4);
// PAL: 0x80647ecc
extern UNKNOWN_FUNCTION(unk_80647ecc);
// PAL: 0x806484a8
extern UNKNOWN_FUNCTION(unk_806484a8);
// PAL: 0x80648de8
extern UNKNOWN_FUNCTION(unk_80648de8);
// PAL: 0x80649470
extern UNKNOWN_FUNCTION(unk_80649470);
// PAL: 0x80649988
extern UNKNOWN_FUNCTION(unk_80649988);
// PAL: 0x8064a0b0
extern UNKNOWN_FUNCTION(unk_8064a0b0);
// PAL: 0x8064a3f4
extern UNKNOWN_FUNCTION(unk_8064a3f4);
// PAL: 0x8064aef8
extern UNKNOWN_FUNCTION(unk_8064aef8);
// PAL: 0x8064b640
extern UNKNOWN_FUNCTION(unk_8064b640);
// PAL: 0x8064bfd8
extern UNKNOWN_FUNCTION(unk_8064bfd8);
// PAL: 0x8064c7c8
extern UNKNOWN_FUNCTION(unk_8064c7c8);
// PAL: 0x8064d834
extern UNKNOWN_FUNCTION(unk_8064d834);
// PAL: 0x8064dee8
extern UNKNOWN_FUNCTION(unk_8064dee8);
// PAL: 0x8064e9d0
extern UNKNOWN_FUNCTION(unk_8064e9d0);
// PAL: 0x8064f168
extern UNKNOWN_FUNCTION(unk_8064f168);
// PAL: 0x8064f9d8
extern UNKNOWN_FUNCTION(unk_8064f9d8);
// PAL: 0x8064fbdc
extern UNKNOWN_FUNCTION(unk_8064fbdc);
// PAL: 0x80651e80
extern UNKNOWN_FUNCTION(unk_80651e80);
// PAL: 0x80652774
extern UNKNOWN_FUNCTION(YesNoPage_construct);
// PAL: 0x80652d7c
extern UNKNOWN_FUNCTION(unk_80652d7c);
// PAL: 0x806561a8
extern UNKNOWN_FUNCTION(unk_806561a8);
// PAL: 0x80656e44
extern UNKNOWN_FUNCTION(unk_80656e44);
// PAL: 0x80665538
extern UNKNOWN_FUNCTION(unk_80665538);
// PAL: 0x80665a4c
extern UNKNOWN_FUNCTION(unk_80665a4c);
// PAL: 0x80665fec
extern UNKNOWN_FUNCTION(unk_80665fec);
// PAL: 0x80666768
extern UNKNOWN_FUNCTION(unk_80666768);
// PAL: 0x806672a4
extern UNKNOWN_FUNCTION(unk_806672a4);
// PAL: 0x80667f24
extern UNKNOWN_FUNCTION(unk_80667f24);
// PAL: 0x8067ac00
extern UNKNOWN_FUNCTION(unk_8067ac00);
// PAL: 0x8067dab0
extern UNKNOWN_FUNCTION(unk_8067dab0);
// PAL: 0x8067dad0
extern UNKNOWN_FUNCTION(unk_8067dad0);
// PAL: 0x80715ecc
extern UNKNOWN_FUNCTION(unk_80715ecc);
// PAL: 0x80715f60
extern UNKNOWN_FUNCTION(unk_80715f60);
// PAL: 0x808556e4
extern UNKNOWN_FUNCTION(TimeAttackSplitsPage_ct); // Extern data references.
// PAL: 0x802a3ee8
extern UNKNOWN_DATA(lbl_802a3ee8);
// PAL: 0x80385fc8
extern UNKNOWN_DATA(lbl_80385fc8);
// PAL: 0x80386000
extern UNKNOWN_DATA(sInstance__Q26System13SystemManager);
// PAL: 0x80386170
extern UNKNOWN_DATA(lbl_80386170);
// PAL: 0x80386f10
extern UNKNOWN_DATA(lbl_80386f10);
// PAL: 0x80897d40
extern UNKNOWN_DATA(lbl_80897d40);
// PAL: 0x80897d44
extern UNKNOWN_DATA(lbl_80897d44);
// PAL: 0x80897d70
extern UNKNOWN_DATA(lbl_80897d70);
// PAL: 0x808bba38
extern UNKNOWN_DATA(jtbl_808bba38);
// PAL: 0x809c1848
extern UNKNOWN_DATA(lbl_809c1848);
// PAL: 0x809c1874
extern UNKNOWN_DATA(lbl_809c1874);
// PAL: 0x809c1be4
extern UNKNOWN_DATA(lbl_809c1be4);
// PAL: 0x809c1e38
extern UNKNOWN_DATA(lbl_809c1e38);
// PAL: 0x809c20d8
extern UNKNOWN_DATA(lbl_809c20d8);
// PAL: 0x809c21d0
extern UNKNOWN_DATA(lbl_809c21d0);
// PAL: 0x809c2850
extern UNKNOWN_DATA(lbl_809c2850);
}

// --- EXTERN DECLARATIONS END ---

// .rodata

// .data

// .bss

// Symbol: Section_construct
// PAL: 0x80621d0c..0x80621d84
MARK_BINARY_BLOB(Section_construct, 0x80621d0c, 0x80621d84);
asm UNKNOWN_FUNCTION(Section_construct){
#include "asm/80621d0c.s"
}

// Symbol: Section_destroy
// PAL: 0x80621d84..0x80621e00
MARK_BINARY_BLOB(Section_destroy, 0x80621d84, 0x80621e00);
asm UNKNOWN_FUNCTION(Section_destroy){
#include "asm/80621d84.s"
}

// Symbol: Section_init
// PAL: 0x80621e00..0x806220b0
MARK_BINARY_BLOB(Section_init, 0x80621e00, 0x806220b0);
asm UNKNOWN_FUNCTION(Section_init){
#include "asm/80621e00.s"
}

// Symbol: Section_load
// PAL: 0x806220b0..0x806221d8
MARK_BINARY_BLOB(Section_load, 0x806220b0, 0x806221d8);
asm UNKNOWN_FUNCTION(Section_load){
#include "asm/806220b0.s"
}

// Symbol: Section_deinit
// PAL: 0x806221d8..0x806223a0
MARK_BINARY_BLOB(Section_deinit, 0x806221d8, 0x806223a0);
asm UNKNOWN_FUNCTION(Section_deinit){
#include "asm/806221d8.s"
}

// Symbol: unk_806223a0
// PAL: 0x806223a0..0x806224f8
MARK_BINARY_BLOB(unk_806223a0, 0x806223a0, 0x806224f8);
asm UNKNOWN_FUNCTION(unk_806223a0){
#include "asm/806223a0.s"
}

// Symbol: Section_calc
// PAL: 0x806224f8..0x80622764
MARK_BINARY_BLOB(Section_calc, 0x806224f8, 0x80622764);
asm UNKNOWN_FUNCTION(Section_calc){
#include "asm/806224f8.s"
}

// Symbol: Section_draw
// PAL: 0x80622764..0x80622ae0
MARK_BINARY_BLOB(Section_draw, 0x80622764, 0x80622ae0);
asm UNKNOWN_FUNCTION(Section_draw){
#include "asm/80622764.s"
}

// Symbol: unk_80622ae0
// PAL: 0x80622ae0..0x80622b4c
MARK_BINARY_BLOB(unk_80622ae0, 0x80622ae0, 0x80622b4c);
asm UNKNOWN_FUNCTION(unk_80622ae0){
#include "asm/80622ae0.s"
}

// Symbol: unk_80622b4c
// PAL: 0x80622b4c..0x80622c08
MARK_BINARY_BLOB(unk_80622b4c, 0x80622b4c, 0x80622c08);
asm UNKNOWN_FUNCTION(unk_80622b4c){
#include "asm/80622b4c.s"
}

// Symbol: unk_80622c08
// PAL: 0x80622c08..0x80622c68
MARK_BINARY_BLOB(unk_80622c08, 0x80622c08, 0x80622c68);
asm UNKNOWN_FUNCTION(unk_80622c08){
#include "asm/80622c08.s"
}

// Symbol: unk_80622c68
// PAL: 0x80622c68..0x80622cb8
MARK_BINARY_BLOB(unk_80622c68, 0x80622c68, 0x80622cb8);
asm UNKNOWN_FUNCTION(unk_80622c68){
#include "asm/80622c68.s"
}

// Symbol: unk_80622cb8
// PAL: 0x80622cb8..0x80622d08
MARK_BINARY_BLOB(unk_80622cb8, 0x80622cb8, 0x80622d08);
asm UNKNOWN_FUNCTION(unk_80622cb8){
#include "asm/80622cb8.s"
}

// Symbol: Section_addPage
// PAL: 0x80622d08..0x80622d54
MARK_BINARY_BLOB(Section_addPage, 0x80622d08, 0x80622d54);
asm UNKNOWN_FUNCTION(Section_addPage){
#include "asm/80622d08.s"
}

// Symbol: unk_80622d54
// PAL: 0x80622d54..0x80622da0
MARK_BINARY_BLOB(unk_80622d54, 0x80622d54, 0x80622da0);
asm UNKNOWN_FUNCTION(unk_80622d54){
#include "asm/80622d54.s"
}

// Symbol: Section_addActivePage
// PAL: 0x80622da0..0x80622e00
MARK_BINARY_BLOB(Section_addActivePage, 0x80622da0, 0x80622e00);
asm UNKNOWN_FUNCTION(Section_addActivePage){
#include "asm/80622da0.s"
}

// Symbol: Section_activatePage
// PAL: 0x80622e00..0x80622e6c
MARK_BINARY_BLOB(Section_activatePage, 0x80622e00, 0x80622e6c);
asm UNKNOWN_FUNCTION(Section_activatePage){
#include "asm/80622e00.s"
}

// Symbol: Section_isPageActive
// PAL: 0x80622e6c..0x80622ea0
MARK_BINARY_BLOB(Section_isPageActive, 0x80622e6c, 0x80622ea0);
asm UNKNOWN_FUNCTION(Section_isPageActive){
#include "asm/80622e6c.s"
}

// Symbol: Section_getVisiblePage
// PAL: 0x80622ea0..0x80622ec8
MARK_BINARY_BLOB(Section_getVisiblePage, 0x80622ea0, 0x80622ec8);
asm UNKNOWN_FUNCTION(Section_getVisiblePage){
#include "asm/80622ea0.s"
}

// Symbol: unk_80622ec8
// PAL: 0x80622ec8..0x80622f88
MARK_BINARY_BLOB(unk_80622ec8, 0x80622ec8, 0x80622f88);
asm UNKNOWN_FUNCTION(unk_80622ec8){
#include "asm/80622ec8.s"
}

// Symbol: unk_80622f88
// PAL: 0x80622f88..0x80623054
MARK_BINARY_BLOB(unk_80622f88, 0x80622f88, 0x80623054);
asm UNKNOWN_FUNCTION(unk_80622f88){
#include "asm/80622f88.s"
}

// Symbol: unk_80623054
// PAL: 0x80623054..0x80623068
MARK_BINARY_BLOB(unk_80623054, 0x80623054, 0x80623068);
asm UNKNOWN_FUNCTION(unk_80623054){
#include "asm/80623054.s"
}

// Symbol: Section_calcActivation
// PAL: 0x80623068..0x80623228
MARK_BINARY_BLOB(Section_calcActivation, 0x80623068, 0x80623228);
asm UNKNOWN_FUNCTION(Section_calcActivation){
#include "asm/80623068.s"
}

// Symbol: unk_80623228
// PAL: 0x80623228..0x80623288
MARK_BINARY_BLOB(unk_80623228, 0x80623228, 0x80623288);
asm UNKNOWN_FUNCTION(unk_80623228){
#include "asm/80623228.s"
}

// Symbol: unk_80623288
// PAL: 0x80623288..0x806232e8
MARK_BINARY_BLOB(unk_80623288, 0x80623288, 0x806232e8);
asm UNKNOWN_FUNCTION(unk_80623288){
#include "asm/80623288.s"
}

// Symbol: unk_806232e8
// PAL: 0x806232e8..0x80623390
MARK_BINARY_BLOB(unk_806232e8, 0x806232e8, 0x80623390);
asm UNKNOWN_FUNCTION(unk_806232e8){
#include "asm/806232e8.s"
}

// Symbol: Section_createPage
// PAL: 0x80623390..0x80624690
MARK_BINARY_BLOB(Section_createPage, 0x80623390, 0x80624690);
asm UNKNOWN_FUNCTION(Section_createPage) {
#include "asm/80623390.s"
}
