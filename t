.text:02588A68
.text:02588A68 # LivingEntity::tick((void))
.text:02588A68 tick__12LivingEntityFv:                 # DATA XREF: ArmorStand::tick((void))+134↑o
.text:02588A68                                         # Mob::tick((void))+48↓o ...
.text:02588A68
.text:02588A68 .set back_chain, -0x98
.text:02588A68 .set var_90, -0x90
.text:02588A68 .set var_80, -0x80
.text:02588A68 .set var_7C, -0x7C
.text:02588A68 .set var_78, -0x78
.text:02588A68 .set var_74, -0x74
.text:02588A68 .set var_70, -0x70
.text:02588A68 .set var_68, -0x68
.text:02588A68 .set var_60, -0x60
.text:02588A68 .set var_58, -0x58
.text:02588A68 .set var_50, -0x50
.text:02588A68 .set var_48, -0x48
.text:02588A68 .set var_40, -0x40
.text:02588A68 .set var_38, -0x38
.text:02588A68 .set var_30, -0x30
.text:02588A68 .set var_28, -0x28
.text:02588A68 .set var_20, -0x20
.text:02588A68 .set var_18, -0x18
.text:02588A68 .set var_10, -0x10
.text:02588A68 .set var_8, -8
.text:02588A68 .set sender_lr,  4
.text:02588A68
.text:02588A68                 stwu      r1, back_chain(r1)
.text:02588A6C                 stfd      f29, 0x98+var_30(r1)
.text:02588A70                 ps_merge10 f29, f29, f29
.text:02588A74                 stfd      f27, 0x98+var_50(r1)
.text:02588A78                 ps_merge10 f27, f27, f27
.text:02588A7C                 stw       r30, 0x98+var_78(r1)
.text:02588A80                 stfd      f31, 0x98+var_10(r1)
.text:02588A84                 mflr      r0
.text:02588A88                 stfs      f29, 0x98+var_28(r1)
.text:02588A8C                 ps_merge10 f31, f31, f31
.text:02588A90                 stfd      f30, 0x98+var_20(r1)
.text:02588A94                 stw       r28, 0x98+var_80(r1)
.text:02588A98                 ps_merge10 f30, f30, f30
.text:02588A9C                 stfs      f31, 0x98+var_8(r1)
.text:02588AA0                 mr        r30, r3
.text:02588AA4                 stfs      f30, 0x98+var_18(r1)
.text:02588AA8                 stfd      f28, 0x98+var_40(r1)
.text:02588AAC                 stw       r0, 0x98+sender_lr(r1)
.text:02588AB0                 ps_merge10 f28, f28, f28
.text:02588AB4                 stfs      f27, 0x98+var_48(r1)
.text:02588AB8                 stfs      f28, 0x98+var_38(r1)
.text:02588ABC                 stfd      f26, 0x98+var_60(r1)
.text:02588AC0                 stw       r31, 0x98+var_74(r1)
.text:02588AC4                 stfd      f25, 0x98+var_70(r1)
.text:02588AC8                 ps_merge10 f26, f26, f26
.text:02588ACC                 stw       r29, 0x98+var_7C(r1)
.text:02588AD0                 ps_merge10 f25, f25, f25
.text:02588AD4                 stfs      f26, 0x98+var_58(r1)
.text:02588AD8                 stfs      f25, 0x98+var_68(r1)
.text:02588ADC                 lis       r12, PIXBeginNamedEvent__FfPCce@ha
.text:02588AE0                 lis       r7, flt_10158804@ha
.text:02588AE4                 addi      r12, r12, PIXBeginNamedEvent__FfPCce@l # PIXBeginNamedEvent(float,char const *,...)
.text:02588AE8                 lfs       f31, flt_10158804@l(r7)
.text:02588AEC                 mtctr     r12
.text:02588AF0                 lis       r3, aLivingEntityTi@ha
.text:02588AF4                 addi      r3, r3, aLivingEntityTi@l # "Living entity tick"
.text:02588AF8                 fmr       f1, f31
.text:02588AFC                 crclr     4*cr1+eq
.text:02588B00                 bctrl
.text:02588B04                 lis       r12, newTemp__4AABBSFPC4AABB@ha
.text:02588B08                 addi      r12, r12, newTemp__4AABBSFPC4AABB@l
.text:02588B0C                 mtctr     r12
.text:02588B10                 lwz       r3, 0x158(r30)
.text:02588B14                 bctrl
.text:02588B18                 lis       r12, buildCache__15EntityTickCacheFP5LevelP4AABB@ha
.text:02588B1C                 addi      r12, r12, buildCache__15EntityTickCacheFP5LevelP4AABB@l # EntityTickCache::buildCache((Level *,AABB *))
.text:02588B20                 mr        r5, r3
.text:02588B24                 mtctr     r12
.text:02588B28                 lwz       r4, 0xF8(r30)
.text:02588B2C                 addi      r3, r30, 0x24 # '$'
.text:02588B30                 bctrl
.text:02588B34                 lis       r12, tick__6EntityFv@ha
.text:02588B38                 addi      r12, r12, tick__6EntityFv@l # Entity::tick((void))
.text:02588B3C                 mtctr     r12
.text:02588B40                 mr        r3, r30
.text:02588B44                 bctrl
.text:02588B48                 lwz       r11, 0x348(r30)
.text:02588B4C                 lwz       r0, 0xB8C(r11)
.text:02588B50                 mtctr     r0
.text:02588B54                 mr        r3, r30
.text:02588B58                 bctrl
.text:02588B5C                 lwz       r5, 0xF8(r30)
.text:02588B60                 lbz       r0, 0x168(r5)
.text:02588B64                 cmpwi     r0, 0
.text:02588B68                 bne       loc_2588CB8
.text:02588B6C                 lwz       r7, 0x348(r30)
.text:02588B70                 lwz       r8, 0xA04(r7)
.text:02588B74                 mtctr     r8
.text:02588B78                 mr        r3, r30
.text:02588B7C                 bctrl
.text:02588B80                 cmpwi     r3, 0
.text:02588B84                 ble       loc_2588BC0
.text:02588B88                 lwz       r7, 0x3A0(r30)
.text:02588B8C                 cmpwi     r7, 0
.text:02588B90                 bgt       loc_2588B9C
.text:02588B94                 mulli     r9, r3, 0x14
.text:02588B98                 subfic    r7, r9, 0x258
.text:02588B9C
.text:02588B9C loc_2588B9C:                            # CODE XREF: LivingEntity::tick((void))+128↑j
.text:02588B9C                 addic.    r7, r7, -1
.text:02588BA0                 stw       r7, 0x3A0(r30)
.text:02588BA4                 bgt       loc_2588BC0
.text:02588BA8                 lwz       r10, 0x348(r30)
.text:02588BAC                 lwz       r11, 0xA0C(r10)
.text:02588BB0                 addi      r4, r3, -1
.text:02588BB4                 mtctr     r11
.text:02588BB8                 mr        r3, r30
.text:02588BBC                 bctrl
.text:02588BC0
.text:02588BC0 loc_2588BC0:                            # CODE XREF: LivingEntity::tick((void))+11C↑j
.text:02588BC0                                         # LivingEntity::tick((void))+13C↑j
.text:02588BC0                 lis       r12, updateEquipmentSlots__12LivingEntityFv@ha
.text:02588BC4                 addi      r12, r12, updateEquipmentSlots__12LivingEntityFv@l # LivingEntity::updateEquipmentSlots((void))
.text:02588BC8                 mtctr     r12
.text:02588BCC                 mr        r3, r30
.text:02588BD0                 bctrl
.text:02588BD4                 lis       r9, 0x6666
.text:02588BD8                 lwz       r0, 0x1E8(r30)
.text:02588BDC                 addi      r9, r9, 0x6667 # 0x66666667
.text:02588BE0                 mulhw     r7, r9, r0
.text:02588BE4                 srawi     r8, r0, 0x1F
.text:02588BE8                 srawi     r7, r7, 3
.text:02588BEC                 subf      r7, r8, r7
.text:02588BF0                 mulli     r7, r7, 0x14
.text:02588BF4                 subf.     r12, r7, r0
.text:02588BF8                 bne       loc_2588C50
.text:02588BFC                 lis       r12, PIXBeginNamedEvent__FfPCce@ha
.text:02588C00                 lis       r3, aRecheckCombatT@ha
.text:02588C04                 addi      r12, r12, PIXBeginNamedEvent__FfPCce@l # PIXBeginNamedEvent(float,char const *,...)
.text:02588C08                 mtctr     r12
.text:02588C0C                 addi      r3, r3, aRecheckCombatT@l # "Recheck combat tracker status"
.text:02588C10                 fmr       f1, f31
.text:02588C14                 crclr     4*cr1+eq
.text:02588C18                 bctrl
.text:02588C1C                 lwz       r10, 0x348(r30)
.text:02588C20                 lwz       r0, 0x9EC(r10)
.text:02588C24                 mtctr     r0
.text:02588C28                 mr        r3, r30
.text:02588C2C                 bctrl
.text:02588C30                 lis       r12, recheckStatus__13CombatTrackerFv@ha
.text:02588C34                 addi      r12, r12, recheckStatus__13CombatTrackerFv@l # CombatTracker::recheckStatus((void))
.text:02588C38                 mtctr     r12
.text:02588C3C                 bctrl
.text:02588C40                 lis       r12, PIXEndNamedEvent__Fv@ha
.text:02588C44                 addi      r12, r12, PIXEndNamedEvent__Fv@l # PIXEndNamedEvent(void)
.text:02588C48                 mtctr     r12
.text:02588C4C                 bctrl
.text:02588C50
.text:02588C50 loc_2588C50:                            # CODE XREF: LivingEntity::tick((void))+190↑j
.text:02588C50                 lbz       r5, 0x2AC(r30)
.text:02588C54                 cmpwi     r5, 0
.text:02588C58                 bne       loc_2588CB8
.text:02588C5C                 lwz       r8, 0x348(r30)
.text:02588C60                 lwz       r0, 0x8CC(r8)
.text:02588C64                 lis       r4, dword_104C3768@ha
.text:02588C68                 mtctr     r0
.text:02588C6C                 lwz       r4, dword_104C3768@l(r4)
.text:02588C70                 mr        r3, r30
.text:02588C74                 bctrl
.text:02588C78                 lis       r12, getSharedFlag__6EntityFi@ha
.text:02588C7C                 addi      r12, r12, getSharedFlag__6EntityFi@l # Entity::getSharedFlag((int))
.text:02588C80                 mr        r31, r3
.text:02588C84                 mtctr     r12
.text:02588C88                 mr        r3, r30
.text:02588C8C                 li        r4, 8
.text:02588C90                 bctrl
.text:02588C94                 cmplw     r3, r31
.text:02588C98                 beq       loc_2588CB8
.text:02588C9C                 lis       r12, setSharedFlag__6EntityFib@ha
.text:02588CA0                 addi      r12, r12, setSharedFlag__6EntityFib@l # Entity::setSharedFlag((int,bool))
.text:02588CA4                 mtctr     r12
.text:02588CA8                 li        r4, 8
.text:02588CAC                 mr        r5, r31
.text:02588CB0                 mr        r3, r30
.text:02588CB4                 bctrl
.text:02588CB8
.text:02588CB8 loc_2588CB8:                            # CODE XREF: LivingEntity::tick((void))+100↑j
.text:02588CB8                                         # LivingEntity::tick((void))+1F0↑j ...
.text:02588CB8                 lwz       r3, 0x4A8(r30)
.text:02588CBC                 cmpwi     r3, 0
.text:02588CC0                 beq       loc_2588CD4
.text:02588CC4                 lis       r12, tick__17InsomniaComponentFv@ha
.text:02588CC8                 addi      r12, r12, tick__17InsomniaComponentFv@l # InsomniaComponent::tick((void))
.text:02588CCC                 mtctr     r12
.text:02588CD0                 bctrl
.text:02588CD4
.text:02588CD4 loc_2588CD4:                            # CODE XREF: LivingEntity::tick((void))+258↑j
.text:02588CD4                 lfs       f0, 0x198(r30)
.text:02588CD8                 lis       r10, flt_10163C20@ha
.text:02588CDC                 lis       r12, __ct__8BlockPosFdN21@ha
.text:02588CE0                 lfs       f13, flt_10163C20@l(r10)
.text:02588CE4                 addi      r12, r12, __ct__8BlockPosFdN21@l
.text:02588CE8                 lwz       r28, 0xF8(r30)
.text:02588CEC                 fmuls     f0, f0, f13
.text:02588CF0                 lfd       f8, 0x118(r30)
.text:02588CF4                 mtctr     r12
.text:02588CF8                 lfd       f11, 0x128(r30)
.text:02588CFC                 fadd      f1, f8, f0
.text:02588D00                 lwz       r31, 0(r28)
.text:02588D04                 fadd      f3, f11, f0
.text:02588D08                 lfd       f2, 0x120(r30)
.text:02588D0C                 addi      r3, r1, 0x98+var_90
.text:02588D10                 bctrl
.text:02588D14                 lwz       r8, 0x44(r31)
.text:02588D18                 mtctr     r8
.text:02588D1C                 mr        r5, r3
.text:02588D20                 addi      r4, r30, 0x24 # '$'
.text:02588D24                 mr        r3, r28
.text:02588D28                 bctrl
.text:02588D2C                 lwz       r9, 0(r3)
.text:02588D30                 lwz       r0, 0x17C(r9)
.text:02588D34                 mtctr     r0
.text:02588D38                 mr        r29, r3
.text:02588D3C                 bctrl
.text:02588D40                 lis       r12, getId__5BlockSFP5Block@ha
.text:02588D44                 addi      r12, r12, getId__5BlockSFP5Block@l
.text:02588D48                 mtctr     r12
.text:02588D4C                 bctrl
.text:02588D50                 cmpwi     r3, 0x110
.text:02588D54                 li        r31, 0
.text:02588D58                 bne       loc_2588F4C
.text:02588D5C                 lbz       r5, 0x5E8(r30)
.text:02588D60                 cmpwi     r5, 0
.text:02588D64                 bne       loc_2588EAC
.text:02588D68                 lwz       r7, 0(r29)
.text:02588D6C                 lis       r4, dword_104D7818@ha
.text:02588D70                 lwz       r8, 0x15C(r7)
.text:02588D74                 lwz       r4, dword_104D7818@l(r4)
.text:02588D78                 mtctr     r8
.text:02588D7C                 mr        r3, r29
.text:02588D80                 bctrl
.text:02588D84                 lwz       r9, 4(r3)
.text:02588D88                 lwz       r11, 0x1C(r9)
.text:02588D8C                 lis       r4, off_101591A0@ha
.text:02588D90                 mtctr     r11
.text:02588D94                 mr        r29, r3
.text:02588D98                 addi      r4, r4, off_101591A0@l
.text:02588D9C                 bctrl
.text:02588DA0                 cmpwi     r3, 0
.text:02588DA4                 bne       loc_2588DAC
.text:02588DA8                 li        r29, 0
.text:02588DAC
.text:02588DAC loc_2588DAC:                            # CODE XREF: LivingEntity::tick((void))+33C↑j
.text:02588DAC                 lfd       f3, 0x128(r30)
.text:02588DB0                 lis       r6, flt_10163CFC@ha
.text:02588DB4                 lwz       r3, 0xF8(r30)
.text:02588DB8                 lis       r12, flt_10164D10@ha
.text:02588DBC                 lfs       f6, flt_10163CFC@l(r6)
.text:02588DC0                 lfs       f4, flt_10164D10@l(r12)
.text:02588DC4                 lwz       r12, 0(r3)
.text:02588DC8                 lbz       r0, 8(r29)
.text:02588DCC                 lis       r10, flt_10163C24@ha
.text:02588DD0                 lwz       r9, 0x1CC(r12)
.text:02588DD4                 cmpwi     r0, 0
.text:02588DD8                 lfd       f1, 0x118(r30)
.text:02588DDC                 mr        r6, r31
.text:02588DE0                 li        r5, 7
.text:02588DE4                 lfs       f5, flt_10163C24@l(r10)
.text:02588DE8                 mtctr     r9
.text:02588DEC                 lfd       f2, 0x120(r30)
.text:02588DF0                 beq       loc_2588EA0
.text:02588DF4                 lis       r4, dword_104C4A18@ha
.text:02588DF8                 lwz       r4, dword_104C4A18@l(r4)
.text:02588DFC                 bctrl
.text:02588E00                 lis       r12, PIXBeginNamedEvent__FfPCce@ha
.text:02588E04                 li        r6, 1
.text:02588E08                 addi      r12, r12, PIXBeginNamedEvent__FfPCce@l # PIXBeginNamedEvent(float,char const *,...)
.text:02588E0C                 lis       r3, aAistep@ha
.text:02588E10                 mtctr     r12
.text:02588E14                 fmr       f1, f31
.text:02588E18                 stb       r6, 0x5E8(r30)
.text:02588E1C                 addi      r3, r3, aAistep@l # "aiStep"
.text:02588E20                 crclr     4*cr1+eq
.text:02588E24                 bctrl
.text:02588E28                 lwz       r10, 0x348(r30)
.text:02588E2C                 lwz       r12, 0xAFC(r10)
.text:02588E30                 mtctr     r12
.text:02588E34                 mr        r3, r30
.text:02588E38                 bctrl
.text:02588E3C                 lis       r12, PIXEndNamedEvent__Fv@ha
.text:02588E40                 addi      r12, r12, PIXEndNamedEvent__Fv@l # PIXEndNamedEvent(void)
.text:02588E44                 mtctr     r12
.text:02588E48                 bctrl
.text:02588E4C                 lfd       f13, 0x110(r30)
.text:02588E50                 lis       r6, flt_10168E70@ha
.text:02588E54                 lfd       f9, 0x128(r30)
.text:02588E58                 lfd       f0, 0x100(r30)
.text:02588E5C                 fsub      f26, f9, f13
.text:02588E60                 lfd       f13, 0x118(r30)
.text:02588E64                 lfs       f10, flt_10168E70@l(r6)
.text:02588E68                 fsub      f25, f13, f0
.text:02588E6C                 fmul      f0, f26, f26
.text:02588E70                 fmadd     f9, f25, f25, f0
.text:02588E74                 lfs       f7, 0x48C(r30)
.text:02588E78                 frsp      f1, f9
.text:02588E7C                 lfs       f27, 0x3E0(r30)
.text:02588E80                 fmr       f29, f31
.text:02588E84                 fcmpu     cr0, f1, f10
.text:02588E88                 stfs      f7, 0x488(r30)
.text:02588E8C                 lis       r12, flt_10168E6C@ha
.text:02588E90                 fmr       f28, f31
.text:02588E94                 lfs       f30, flt_10168E6C@l(r12)
.text:02588E98                 ble       loc_2589094
.text:02588E9C                 b         loc_2588FE8
.text:02588EA0 # ---------------------------------------------------------------------------
.text:02588EA0
.text:02588EA0 loc_2588EA0:                            # CODE XREF: LivingEntity::tick((void))+388↑j
.text:02588EA0                 lis       r4, dword_104C4A10@ha
.text:02588EA4                 lwz       r4, dword_104C4A10@l(r4)
.text:02588EA8                 bctrl
.text:02588EAC
.text:02588EAC loc_2588EAC:                            # CODE XREF: LivingEntity::tick((void))+2FC↑j
.text:02588EAC                 lis       r12, PIXBeginNamedEvent__FfPCce@ha
.text:02588EB0                 li        r6, 1
.text:02588EB4                 addi      r12, r12, PIXBeginNamedEvent__FfPCce@l # PIXBeginNamedEvent(float,char const *,...)
.text:02588EB8                 lis       r3, aAistep@ha
.text:02588EBC                 mtctr     r12
.text:02588EC0                 addi      r3, r3, aAistep@l # "aiStep"
.text:02588EC4                 stb       r6, 0x5E8(r30)
.text:02588EC8                 fmr       f1, f31
.text:02588ECC                 crclr     4*cr1+eq
.text:02588ED0                 bctrl
.text:02588ED4                 lwz       r10, 0x348(r30)
.text:02588ED8                 lwz       r12, 0xAFC(r10)
.text:02588EDC                 mtctr     r12
.text:02588EE0                 mr        r3, r30
.text:02588EE4                 bctrl
.text:02588EE8                 lis       r12, PIXEndNamedEvent__Fv@ha
.text:02588EEC                 addi      r12, r12, PIXEndNamedEvent__Fv@l # PIXEndNamedEvent(void)
.text:02588EF0                 mtctr     r12
.text:02588EF4                 bctrl
.text:02588EF8                 lfd       f9, 0x128(r30)
.text:02588EFC                 lis       r6, flt_10168E70@ha
.text:02588F00                 lfd       f13, 0x110(r30)
.text:02588F04                 lfd       f0, 0x100(r30)
.text:02588F08                 fsub      f26, f9, f13
.text:02588F0C                 lfd       f13, 0x118(r30)
.text:02588F10                 lfs       f10, flt_10168E70@l(r6)
.text:02588F14                 fsub      f25, f13, f0
.text:02588F18                 fmul      f0, f26, f26
.text:02588F1C                 fmadd     f9, f25, f25, f0
.text:02588F20                 lfs       f7, 0x48C(r30)
.text:02588F24                 frsp      f1, f9
.text:02588F28                 lfs       f27, 0x3E0(r30)
.text:02588F2C                 fmr       f29, f31
.text:02588F30                 fcmpu     cr0, f1, f10
.text:02588F34                 stfs      f7, 0x488(r30)
.text:02588F38                 lis       r12, flt_10168E6C@ha
.text:02588F3C                 fmr       f28, f31
.text:02588F40                 lfs       f30, flt_10168E6C@l(r12)
.text:02588F44                 ble       loc_2589094
.text:02588F48                 b         loc_2588FE8
.text:02588F4C # ---------------------------------------------------------------------------
.text:02588F4C
.text:02588F4C loc_2588F4C:                            # CODE XREF: LivingEntity::tick((void))+2F0↑j
.text:02588F4C                 lis       r12, PIXBeginNamedEvent__FfPCce@ha
.text:02588F50                 li        r6, 0
.text:02588F54                 addi      r12, r12, PIXBeginNamedEvent__FfPCce@l # PIXBeginNamedEvent(float,char const *,...)
.text:02588F58                 lis       r3, aAistep@ha
.text:02588F5C                 mtctr     r12
.text:02588F60                 addi      r3, r3, aAistep@l # "aiStep"
.text:02588F64                 stb       r6, 0x5E8(r30)
.text:02588F68                 fmr       f1, f31
.text:02588F6C                 crclr     4*cr1+eq
.text:02588F70                 bctrl
.text:02588F74                 lwz       r10, 0x348(r30)
.text:02588F78                 lwz       r12, 0xAFC(r10)
.text:02588F7C                 mtctr     r12
.text:02588F80                 mr        r3, r30
.text:02588F84                 bctrl
.text:02588F88                 lis       r12, PIXEndNamedEvent__Fv@ha
.text:02588F8C                 addi      r12, r12, PIXEndNamedEvent__Fv@l # PIXEndNamedEvent(void)
.text:02588F90                 mtctr     r12
.text:02588F94                 bctrl
.text:02588F98                 lfd       f9, 0x128(r30)
.text:02588F9C                 lis       r6, flt_10168E70@ha
.text:02588FA0                 lfd       f13, 0x110(r30)
.text:02588FA4                 lfd       f0, 0x100(r30)
.text:02588FA8                 fsub      f26, f9, f13
.text:02588FAC                 lfd       f13, 0x118(r30)
.text:02588FB0                 lfs       f10, flt_10168E70@l(r6)
.text:02588FB4                 fsub      f25, f13, f0
.text:02588FB8                 fmul      f0, f26, f26
.text:02588FBC                 fmadd     f9, f25, f25, f0
.text:02588FC0                 lfs       f7, 0x48C(r30)
.text:02588FC4                 frsp      f1, f9
.text:02588FC8                 lfs       f27, 0x3E0(r30)
.text:02588FCC                 fmr       f29, f31
.text:02588FD0                 fcmpu     cr0, f1, f10
.text:02588FD4                 stfs      f7, 0x488(r30)
.text:02588FD8                 lis       r12, flt_10168E6C@ha
.text:02588FDC                 fmr       f28, f31
.text:02588FE0                 lfs       f30, flt_10168E6C@l(r12)
.text:02588FE4                 ble       loc_2589094
.text:02588FE8
.text:02588FE8 loc_2588FE8:                            # CODE XREF: LivingEntity::tick((void))+434↑j
.text:02588FE8                                         # LivingEntity::tick((void))+4E0↑j
.text:02588FE8                 lis       r12, sqrtf@ha
.text:02588FEC                 addi      r12, r12, sqrtf@l
.text:02588FF0                 lis       r11, flt_10163C24@ha
.text:02588FF4                 mtctr     r12
.text:02588FF8                 lfs       f28, flt_10163C24@l(r11)
.text:02588FFC                 bctrl
.text:02589000                 lis       r10, flt_10163CF0@ha
.text:02589004                 lis       r12, atan2@ha
.text:02589008                 lfs       f0, flt_10163CF0@l(r10)
.text:0258900C                 addi      r12, r12, atan2@l
.text:02589010                 fmuls     f29, f1, f0
.text:02589014                 mtctr     r12
.text:02589018                 fmr       f1, f26
.text:0258901C                 fmr       f2, f25
.text:02589020                 bctrl
.text:02589024                 lis       r12, wrapDegrees__3MthSFf@ha
.text:02589028                 lis       r9, flt_10168E74@ha
.text:0258902C                 addi      r12, r12, wrapDegrees__3MthSFf@l
.text:02589030                 lis       r8, flt_101A4650@ha
.text:02589034                 mtctr     r12
.text:02589038                 lfs       f12, flt_101A4650@l(r8)
.text:0258903C                 frsp      f7, f1
.text:02589040                 lfs       f13, flt_10168E74@l(r9)
.text:02589044                 lfs       f1, 0x148(r30)
.text:02589048                 fmsubs    f27, f7, f12, f13
.text:0258904C                 bctrl
.text:02589050                 lis       r12, abs__3MthSFf@ha
.text:02589054                 addi      r12, r12, abs__3MthSFf@l
.text:02589058                 mtctr     r12
.text:0258905C                 fsubs     f1, f1, f27
.text:02589060                 bctrl
.text:02589064                 lis       r5, flt_10168E78@ha
.text:02589068                 lfs       f0, flt_10168E78@l(r5)
.text:0258906C                 fcmpu     cr0, f0, f1
.text:02589070                 bge       loc_2589090
.text:02589074                 lis       r11, flt_10168E7C@ha
.text:02589078                 lfs       f7, flt_10168E7C@l(r11)
.text:0258907C                 fcmpu     cr0, f1, f7
.text:02589080                 bge       loc_2589090
.text:02589084                 fsubs     f27, f27, f30
.text:02589088                 lfs       f7, 0x48C(r30)
.text:0258908C                 b         loc_2589094
.text:02589090 # ---------------------------------------------------------------------------
.text:02589090
.text:02589090 loc_2589090:                            # CODE XREF: LivingEntity::tick((void))+608↑j
.text:02589090                                         # LivingEntity::tick((void))+618↑j
.text:02589090                 lfs       f7, 0x48C(r30)
.text:02589094
.text:02589094 loc_2589094:                            # CODE XREF: LivingEntity::tick((void))+430↑j
.text:02589094                                         # LivingEntity::tick((void))+4DC↑j ...
.text:02589094                 lfs       f13, 0x3B8(r30)
.text:02589098                 fcmpu     cr0, f13, f31
.text:0258909C                 lbz       r0, 0x15C(r30)
.text:025890A0                 ble       loc_25890A8
.text:025890A4                 lfs       f27, 0x148(r30)
.text:025890A8
.text:025890A8 loc_25890A8:                            # CODE XREF: LivingEntity::tick((void))+638↑j
.text:025890A8                 cmpwi     r0, 0
.text:025890AC                 lwz       r12, 0x348(r30)
.text:025890B0                 bne       loc_25890B8
.text:025890B4                 fmr       f28, f31
.text:025890B8
.text:025890B8 loc_25890B8:                            # CODE XREF: LivingEntity::tick((void))+648↑j
.text:025890B8                 lis       r9, flt_10164C40@ha
.text:025890BC                 lwz       r0, 0xAF4(r12)
.text:025890C0                 fsubs     f12, f28, f7
.text:025890C4                 lfs       f9, flt_10164C40@l(r9)
.text:025890C8                 fmr       f1, f27
.text:025890CC                 mtctr     r0
.text:025890D0                 fmadds    f13, f12, f9, f7
.text:025890D4                 fmr       f2, f29
.text:025890D8                 stfs      f13, 0x48C(r30)
.text:025890DC                 mr        r3, r30
.text:025890E0                 bctrl
.text:025890E4                 lfs       f10, 0x148(r30)
.text:025890E8                 lis       r6, flt_10168E84@ha
.text:025890EC                 lfs       f8, 0x150(r30)
.text:025890F0                 lfs       f12, flt_10168E84@l(r6)
.text:025890F4                 lis       r12, flt_10168E80@ha
.text:025890F8                 fsubs     f7, f10, f8
.text:025890FC                 lfs       f11, flt_10168E80@l(r12)
.text:02589100                 fcmpu     cr0, f7, f12
.text:02589104                 fmr       f29, f1
.text:02589108                 bge       loc_2589130
.text:0258910C                 fmr       f7, f12
.text:02589110                 fmr       f0, f11
.text:02589114                 fmr       f9, f10
.text:02589118
.text:02589118 loc_2589118:                            # CODE XREF: LivingEntity::tick((void))+6BC↓j
.text:02589118                 fsubs     f8, f8, f0
.text:0258911C                 fsubs     f13, f9, f8
.text:02589120                 fcmpu     cr0, f13, f7
.text:02589124                 blt       loc_2589118
.text:02589128                 fsubs     f7, f10, f8
.text:0258912C                 stfs      f8, 0x150(r30)
.text:02589130
.text:02589130 loc_2589130:                            # CODE XREF: LivingEntity::tick((void))+6A0↑j
.text:02589130                 fcmpu     cr0, f7, f30
.text:02589134                 blt       loc_2589154
.text:02589138                 fmr       f9, f30
.text:0258913C                 fmr       f0, f11
.text:02589140
.text:02589140 loc_2589140:                            # CODE XREF: LivingEntity::tick((void))+6E4↓j
.text:02589140                 fadds     f8, f8, f0
.text:02589144                 fsubs     f7, f10, f8
.text:02589148                 fcmpu     cr0, f7, f9
.text:0258914C                 bge       loc_2589140
.text:02589150                 stfs      f8, 0x150(r30)
.text:02589154
.text:02589154 loc_2589154:                            # CODE XREF: LivingEntity::tick((void))+6CC↑j
.text:02589154                 lfs       f10, 0x3E0(r30)
.text:02589158                 lfs       f7, 0x3E4(r30)
.text:0258915C                 fsubs     f9, f10, f7
.text:02589160                 fcmpu     cr0, f9, f12
.text:02589164                 bge       loc_258918C
.text:02589168                 fmr       f0, f12
.text:0258916C                 fmr       f13, f11
.text:02589170                 fmr       f8, f10
.text:02589174
.text:02589174 loc_2589174:                            # CODE XREF: LivingEntity::tick((void))+718↓j
.text:02589174                 fsubs     f7, f7, f13
.text:02589178                 fsubs     f9, f8, f7
.text:0258917C                 fcmpu     cr0, f9, f0
.text:02589180                 blt       loc_2589174
.text:02589184                 fsubs     f9, f10, f7
.text:02589188                 stfs      f7, 0x3E4(r30)
.text:0258918C
.text:0258918C loc_258918C:                            # CODE XREF: LivingEntity::tick((void))+6FC↑j
.text:0258918C                 fcmpu     cr0, f9, f30
.text:02589190                 blt       loc_25891B0
.text:02589194                 fmr       f9, f30
.text:02589198                 fmr       f8, f11
.text:0258919C
.text:0258919C loc_258919C:                            # CODE XREF: LivingEntity::tick((void))+740↓j
.text:0258919C                 fadds     f7, f7, f8
.text:025891A0                 fsubs     f0, f10, f7
.text:025891A4                 fcmpu     cr0, f0, f9
.text:025891A8                 bge       loc_258919C
.text:025891AC                 stfs      f7, 0x3E4(r30)
.text:025891B0
.text:025891B0 loc_25891B0:                            # CODE XREF: LivingEntity::tick((void))+728↑j
.text:025891B0                 lfs       f8, 0x14C(r30)
.text:025891B4                 lfs       f0, 0x154(r30)
.text:025891B8                 fsubs     f13, f8, f0
.text:025891BC                 fcmpu     cr0, f13, f12
.text:025891C0                 bge       loc_25891E8
.text:025891C4                 fmr       f10, f12
.text:025891C8                 fmr       f7, f11
.text:025891CC                 fmr       f13, f8
.text:025891D0
.text:025891D0 loc_25891D0:                            # CODE XREF: LivingEntity::tick((void))+774↓j
.text:025891D0                 fsubs     f0, f0, f7
.text:025891D4                 fsubs     f9, f13, f0
.text:025891D8                 fcmpu     cr0, f9, f10
.text:025891DC                 blt       loc_25891D0
.text:025891E0                 fsubs     f13, f8, f0
.text:025891E4                 stfs      f0, 0x154(r30)
.text:025891E8
.text:025891E8 loc_25891E8:                            # CODE XREF: LivingEntity::tick((void))+758↑j
.text:025891E8                 fcmpu     cr0, f13, f30
.text:025891EC                 blt       loc_258920C
.text:025891F0                 fmr       f10, f30
.text:025891F4                 fmr       f7, f11
.text:025891F8
.text:025891F8 loc_25891F8:                            # CODE XREF: LivingEntity::tick((void))+79C↓j
.text:025891F8                 fadds     f0, f0, f7
.text:025891FC                 fsubs     f13, f8, f0
.text:02589200                 fcmpu     cr0, f13, f10
.text:02589204                 bge       loc_25891F8
.text:02589208                 stfs      f0, 0x154(r30)
.text:0258920C
.text:0258920C loc_258920C:                            # CODE XREF: LivingEntity::tick((void))+784↑j
.text:0258920C                 lfs       f9, 0x3E8(r30)
.text:02589210                 lfs       f13, 0x3EC(r30)
.text:02589214                 fsubs     f0, f9, f13
.text:02589218                 fcmpu     cr0, f0, f12
.text:0258921C                 bge       loc_2589240
.text:02589220                 fmr       f8, f11
.text:02589224                 fmr       f10, f9
.text:02589228
.text:02589228 loc_2589228:                            # CODE XREF: LivingEntity::tick((void))+7CC↓j
.text:02589228                 fsubs     f13, f13, f8
.text:0258922C                 fsubs     f7, f10, f13
.text:02589230                 fcmpu     cr0, f7, f12
.text:02589234                 blt       loc_2589228
.text:02589238                 fsubs     f0, f9, f13
.text:0258923C                 stfs      f13, 0x3EC(r30)
.text:02589240
.text:02589240 loc_2589240:                            # CODE XREF: LivingEntity::tick((void))+7B4↑j
.text:02589240                 fcmpu     cr0, f0, f30
.text:02589244                 blt       loc_258925C
.text:02589248
.text:02589248 loc_2589248:                            # CODE XREF: LivingEntity::tick((void))+7EC↓j
.text:02589248                 fadds     f13, f13, f11
.text:0258924C                 fsubs     f12, f9, f13
.text:02589250                 fcmpu     cr0, f12, f30
.text:02589254                 bge       loc_2589248
.text:02589258                 stfs      f13, 0x3EC(r30)
.text:0258925C
.text:0258925C loc_258925C:                            # CODE XREF: LivingEntity::tick((void))+7DC↑j
.text:0258925C                 lwz       r5, 0x348(r30)
.text:02589260                 lfs       f13, 0x490(r30)
.text:02589264                 lwz       r0, 0xBD4(r5)
.text:02589268                 fadds     f13, f13, f29
.text:0258926C                 mtctr     r0
.text:02589270                 stfs      f13, 0x490(r30)
.text:02589274                 mr        r3, r30
.text:02589278                 bctrl
.text:0258927C                 cmpwi     r3, 0
.text:02589280                 beq       loc_25892A4
.text:02589284                 lis       r12, PIXEndNamedEvent__Fv@ha
.text:02589288                 addi      r12, r12, PIXEndNamedEvent__Fv@l # PIXEndNamedEvent(void)
.text:0258928C                 lwz       r31, 0x524(r30)
.text:02589290                 mtctr     r12
.text:02589294                 addi      r31, r31, 1
.text:02589298                 stw       r31, 0x524(r30)
.text:0258929C                 bctrl
.text:025892A0                 b         loc_25892B8
.text:025892A4 # ---------------------------------------------------------------------------
.text:025892A4
.text:025892A4 loc_25892A4:                            # CODE XREF: LivingEntity::tick((void))+818↑j
.text:025892A4                 lis       r12, PIXEndNamedEvent__Fv@ha
.text:025892A8                 addi      r12, r12, PIXEndNamedEvent__Fv@l # PIXEndNamedEvent(void)
.text:025892AC                 mtctr     r12
.text:025892B0                 stw       r31, 0x524(r30)
.text:025892B4                 bctrl
.text:025892B8
.text:025892B8 loc_25892B8:                            # CODE XREF: LivingEntity::tick((void))+838↑j
.text:025892B8                 lwz       r28, 0x98+var_80(r1)
.text:025892BC                 lwz       r29, 0x98+var_7C(r1)
.text:025892C0                 lfs       f26, 0x98+var_58(r1)
.text:025892C4                 lfs       f25, 0x98+var_68(r1)
.text:025892C8                 lfd       f26, 0x98+var_60(r1)
.text:025892CC                 lfs       f27, 0x98+var_48(r1)
.text:025892D0                 lfd       f25, 0x98+var_70(r1)
.text:025892D4                 lfd       f27, 0x98+var_50(r1)
.text:025892D8                 lfs       f28, 0x98+var_38(r1)
.text:025892DC                 lfs       f29, 0x98+var_28(r1)
.text:025892E0                 lfd       f28, 0x98+var_40(r1)
.text:025892E4                 lfd       f29, 0x98+var_30(r1)
.text:025892E8                 lfs       f31, 0x98+var_8(r1)
.text:025892EC                 lfs       f30, 0x98+var_18(r1)
.text:025892F0                 lfd       f31, 0x98+var_10(r1)
.text:025892F4                 lfd       f30, 0x98+var_20(r1)
.text:025892F8                 lwz       r31, 0x98+var_74(r1)
.text:025892FC                 lwz       r30, 0x98+var_78(r1)
.text:02589300                 isync
.text:02589304                 lwz       r0, 0x98+sender_lr(r1)
.text:02589308                 mtlr      r0
.text:0258930C                 addi      r1, r1, 0x98
.text:02589310                 blr
.text:02589310 # End of function LivingEntity::tick((void))