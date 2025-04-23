/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> ecc_p256.o -> r_GF_Jacobian_Point_Double256
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_GF_Jacobian_Point_Double256(int param_1,void *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_204 [44];
  undefined1 auStack_1d8 [44];
  undefined1 auStack_1ac [44];
  undefined1 auStack_180 [44];
  undefined1 auStack_154 [44];
  undefined1 auStack_128 [44];
  undefined1 auStack_fc [44];
  undefined1 auStack_d0 [44];
  undefined1 auStack_a4 [44];
  undefined1 auStack_78 [44];
  undefined1 auStack_4c [44];
  
  iVar3 = param_1 + 0x2c;
  iVar2 = param_1 + 0x58;
  if (((*(uint *)(param_1 + 0x50) < 2) && (*(short *)(param_1 + 0x4c) == 0)) ||
     ((iVar1 = r_notEqual256(param_1,&ecc_Jacobian_InfinityPoint256), iVar1 == 0 &&
      ((iVar1 = r_notEqual256(iVar3,&ecc_Jacobian_InfinityPoint256), iVar1 == 0 &&
       (iVar1 = r_notEqual256(iVar2,&ecc_Jacobian_InfinityPoint256), iVar1 == 0)))))) {
    memcpy(param_2,&ecc_Jacobian_InfinityPoint256,0x22);
    *(undefined4 *)((int)param_2 + 0x24) = _r_ke_msg_send;
    *(undefined4 *)((int)param_2 + 0x28) = _r_assert_err;
    memcpy((void *)((int)param_2 + 0x2c),&ecc_Jacobian_InfinityPoint256,0x22);
    *(undefined4 *)((int)param_2 + 0x50) = _DebugE256PublicKey_x;
    *(undefined4 *)((int)param_2 + 0x54) = _DebugE256PublicKey_y;
    memcpy((void *)((int)param_2 + 0x58),&ecc_Jacobian_InfinityPoint256,0x22);
    *(undefined4 *)((int)param_2 + 0x7c) = _DAT_00013090;
    *(undefined4 *)((int)param_2 + 0x80) = _DAT_00013094;
  }
  else {
    r_AddBigHexModP256(param_1,iVar2,auStack_a4);
    r_SubtractBigHexMod256(param_1,iVar2,auStack_78);
    r_MultiplyBigHexModP256(auStack_a4,auStack_78,auStack_4c);
    r_MultiplyBigHexByUint32_256(auStack_4c,3,auStack_204);
    r_MultiplyBigHexModP256(iVar3,iVar2,auStack_1d8);
    r_MultiplyBigHexModP256(iVar3,auStack_1d8,auStack_4c);
    r_MultiplyBigHexModP256(param_1,auStack_4c,auStack_1ac);
    r_MultiplyBigHexModP256(auStack_204,auStack_78);
    r_MultiplyBigHexByUint32_256(auStack_1ac,8,auStack_4c);
    r_SubtractBigHexMod256(auStack_78,auStack_4c,auStack_180);
    r_MultiplyBigHexModP256(auStack_180,auStack_1d8,auStack_4c);
    r_MultiplyBigHexByUint32_256(auStack_4c,2,param_2);
    r_MultiplyBigHexModP256(iVar3,iVar3,auStack_128);
    r_MultiplyBigHexModP256(auStack_1d8,auStack_154);
    r_MultiplyBigHexModP256(auStack_128,auStack_154,auStack_fc);
    r_MultiplyBigHexByUint32_256(auStack_fc,8,auStack_d0);
    r_MultiplyBigHexByUint32_256(auStack_1ac,4,auStack_a4);
    r_SubtractBigHexMod256(auStack_a4,auStack_180,auStack_78);
    r_MultiplyBigHexModP256(auStack_204,auStack_78,auStack_4c);
    r_SubtractBigHexMod256(auStack_4c,auStack_d0,(void *)((int)param_2 + 0x2c));
    r_MultiplyBigHexModP256(auStack_154,auStack_1d8,auStack_4c);
    r_MultiplyBigHexByUint32_256(auStack_4c,8,(void *)((int)param_2 + 0x58));
  }
  return 0;
}

