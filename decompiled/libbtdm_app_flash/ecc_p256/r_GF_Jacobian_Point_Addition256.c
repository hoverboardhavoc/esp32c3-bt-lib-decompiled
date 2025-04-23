/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> ecc_p256.o -> r_GF_Jacobian_Point_Addition256
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int r_GF_Jacobian_Point_Addition256(void *param_1,undefined *param_2,void *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  void *__s;
  undefined *__src;
  void *__src_00;
  undefined *__src_01;
  void *__src_02;
  undefined1 auStack_2d4 [36];
  undefined4 uStack_2b0;
  undefined4 uStack_2ac;
  undefined1 auStack_2a8 [36];
  undefined4 uStack_284;
  undefined4 uStack_280;
  undefined1 auStack_27c [36];
  undefined4 uStack_258;
  undefined4 uStack_254;
  undefined1 auStack_250 [36];
  undefined4 uStack_22c;
  undefined4 uStack_228;
  undefined1 auStack_224 [36];
  undefined4 uStack_200;
  undefined4 uStack_1fc;
  undefined1 auStack_1f8 [36];
  undefined4 uStack_1d4;
  undefined4 uStack_1d0;
  undefined1 auStack_1cc [36];
  undefined4 uStack_1a8;
  undefined4 uStack_1a4;
  undefined1 auStack_1a0 [36];
  undefined4 uStack_17c;
  undefined4 uStack_178;
  undefined1 auStack_174 [36];
  undefined4 uStack_150;
  undefined4 uStack_14c;
  undefined1 auStack_148 [36];
  undefined4 uStack_124;
  undefined4 uStack_120;
  undefined1 auStack_11c [36];
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  undefined1 auStack_f0 [36];
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  undefined1 auStack_c4 [36];
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined1 auStack_98 [36];
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined1 auStack_6c [36];
  undefined4 uStack_48;
  undefined4 uStack_44;
  
  __src_02 = (void *)((int)param_1 + 0x2c);
  __src_00 = (void *)((int)param_1 + 0x58);
  __src_01 = param_2 + 0x2c;
  __src = param_2 + 0x58;
  __s = (void *)((int)param_3 + 0x2c);
  memset(param_3,0,0x22);
  *(undefined4 *)((int)param_3 + 0x24) = 0;
  *(undefined4 *)((int)param_3 + 0x28) = 0;
  memset(__s,0,0x22);
  *(undefined4 *)((int)param_3 + 0x50) = 0;
  *(undefined4 *)((int)param_3 + 0x54) = 0;
  memset((void *)((int)param_3 + 0x58),0,0x22);
  *(undefined4 *)((int)param_3 + 0x7c) = 0;
  *(undefined4 *)((int)param_3 + 0x80) = 0;
  memset(auStack_2d4,0,0x22);
  uStack_2b0 = 0;
  uStack_2ac = 0;
  memset(auStack_2a8,0,0x22);
  uStack_284 = 0;
  uStack_280 = 0;
  memset(auStack_27c,0,0x22);
  uStack_258 = 0;
  uStack_254 = 0;
  memset(auStack_250,0,0x22);
  uStack_22c = 0;
  uStack_228 = 0;
  memset(auStack_224,0,0x22);
  uStack_200 = 0;
  uStack_1fc = 0;
  memset(auStack_1f8,0,0x22);
  uStack_1d4 = 0;
  uStack_1d0 = 0;
  memset(auStack_1cc,0,0x22);
  uStack_1a8 = 0;
  uStack_1a4 = 0;
  memset(auStack_1a0,0,0x22);
  uStack_17c = 0;
  uStack_178 = 0;
  memset(auStack_174,0,0x22);
  uStack_150 = 0;
  uStack_14c = 0;
  memset(auStack_148,0,0x22);
  uStack_124 = 0;
  uStack_120 = 0;
  memset(auStack_11c,0,0x22);
  uStack_f8 = 0;
  uStack_f4 = 0;
  memset(auStack_f0,0,0x22);
  uStack_cc = 0;
  uStack_c8 = 0;
  iVar1 = r_notEqual256(param_1,&ecc_Jacobian_InfinityPoint256);
  iVar2 = r_notEqual256(param_2,&ecc_Jacobian_InfinityPoint256);
  if (((iVar1 == 0) && (iVar1 = r_notEqual256(__src_02,&ecc_Jacobian_InfinityPoint256), iVar1 == 0))
     && (iVar1 = r_notEqual256(__src_00,&ecc_Jacobian_InfinityPoint256), iVar1 == 0)) {
    if (((iVar2 == 0) &&
        (iVar1 = r_notEqual256(__src_01,&ecc_Jacobian_InfinityPoint256), iVar1 == 0)) &&
       (iVar1 = r_notEqual256(__src,&ecc_Jacobian_InfinityPoint256), iVar1 == 0)) {
      memcpy(param_3,&ecc_Jacobian_InfinityPoint256,0x22);
      param_2 = &ecc_Jacobian_InfinityPoint256;
      *(undefined4 *)((int)param_3 + 0x24) = _r_ke_msg_send;
      *(undefined4 *)((int)param_3 + 0x28) = _r_assert_err;
      memcpy(__s,&ecc_Jacobian_InfinityPoint256,0x22);
      __src = &ecc_Jacobian_InfinityPoint256;
      *(undefined4 *)((int)param_3 + 0x50) = _DebugE256PublicKey_x;
      *(undefined4 *)((int)param_3 + 0x54) = _DebugE256PublicKey_y;
    }
    else {
      memcpy(param_3,param_2,0x22);
      *(undefined4 *)((int)param_3 + 0x24) = *(undefined4 *)(param_2 + 0x24);
      *(undefined4 *)((int)param_3 + 0x28) = *(undefined4 *)(param_2 + 0x28);
      memcpy(__s,__src_01,0x22);
      *(undefined4 *)((int)param_3 + 0x50) = *(undefined4 *)(param_2 + 0x50);
      *(undefined4 *)((int)param_3 + 0x54) = *(undefined4 *)(param_2 + 0x54);
    }
  }
  else {
    if (((iVar2 == 0) &&
        (iVar1 = r_notEqual256(__src_01,&ecc_Jacobian_InfinityPoint256), iVar1 == 0)) &&
       (iVar1 = r_notEqual256(__src,&ecc_Jacobian_InfinityPoint256), iVar1 == 0)) {
      memcpy(param_3,param_1,0x22);
      *(undefined4 *)((int)param_3 + 0x24) = *(undefined4 *)((int)param_1 + 0x24);
      *(undefined4 *)((int)param_3 + 0x28) = *(undefined4 *)((int)param_1 + 0x28);
      memcpy(__s,__src_02,0x22);
      *(undefined4 *)((int)param_3 + 0x50) = *(undefined4 *)((int)param_1 + 0x50);
      *(undefined4 *)((int)param_3 + 0x54) = *(undefined4 *)((int)param_1 + 0x54);
      memcpy((void *)((int)param_3 + 0x58),__src_00,0x22);
      *(undefined4 *)((int)param_3 + 0x7c) = *(undefined4 *)((int)param_1 + 0x7c);
      uVar3 = *(undefined4 *)((int)param_1 + 0x80);
      goto _L189;
    }
    iVar1 = r_notEqual256(param_2,param_1);
    if ((iVar1 != 0) ||
       ((iVar1 = r_notEqual256(__src_01,__src_02), iVar1 == 0 &&
        ((1 < *(uint *)(param_2 + 0x50) || (*(short *)(param_2 + 0x4c) != 0)))))) {
      r_MultiplyBigHexModP256(__src_01,__src_00,auStack_2d4);
      r_MultiplyBigHexModP256(__src_02,__src,auStack_2a8);
      r_MultiplyBigHexModP256(param_2,__src_00,auStack_27c);
      r_MultiplyBigHexModP256(param_1,__src,auStack_250);
      iVar1 = r_notEqual256(auStack_27c,auStack_250);
      if (iVar1 != 0) {
        r_SubtractBigHexMod256(auStack_2d4,auStack_2a8,auStack_224);
        r_SubtractBigHexMod256(auStack_27c,auStack_250,auStack_1f8);
        r_MultiplyBigHexModP256(__src_00,__src,auStack_1a0);
        memset(auStack_c4,0,0x22);
        uStack_a0 = 0;
        uStack_9c = 0;
        memset(auStack_98,0,0x22);
        uStack_74 = 0;
        uStack_70 = 0;
        memset(auStack_6c,0,0x22);
        uStack_48 = 0;
        uStack_44 = 0;
        r_MultiplyBigHexModP256(auStack_1f8,auStack_174);
        r_MultiplyBigHexModP256(auStack_174,auStack_1f8,auStack_148);
        r_MultiplyBigHexModP256(auStack_224,auStack_11c);
        r_MultiplyBigHexModP256(auStack_174,auStack_250,auStack_f0);
        r_MultiplyBigHexByUint32_256(auStack_f0,2,auStack_6c);
        r_MultiplyBigHexModP256(auStack_11c,auStack_1a0,auStack_c4);
        r_SubtractBigHexMod256(auStack_c4,auStack_148,auStack_98);
        r_SubtractBigHexMod256(auStack_98,auStack_6c,auStack_1cc);
        r_MultiplyBigHexModP256(auStack_1f8,auStack_1cc,param_3);
        memset(auStack_c4,0,0x22);
        uStack_a0 = 0;
        uStack_9c = 0;
        memset(auStack_98,0,0x22);
        uStack_74 = 0;
        uStack_70 = 0;
        memset(auStack_6c,0,0x22);
        uStack_48 = 0;
        uStack_44 = 0;
        r_SubtractBigHexMod256(auStack_f0,auStack_1cc,auStack_c4);
        r_MultiplyBigHexModP256(auStack_224,auStack_c4,auStack_98);
        r_MultiplyBigHexModP256(auStack_148,auStack_2a8,auStack_6c);
        r_SubtractBigHexMod256(auStack_98,auStack_6c,__s);
        r_MultiplyBigHexModP256(auStack_148,auStack_1a0,(void *)((int)param_3 + 0x58));
        return iVar1;
      }
      iVar1 = r_notEqual256(auStack_2d4,auStack_2a8);
      if (iVar1 == 0) {
        r_GF_Jacobian_Point_Double256(param_1,param_3);
        return 0;
      }
    }
    memcpy(param_3,&ecc_Jacobian_InfinityPoint256,0x22);
    param_2 = &ecc_Jacobian_InfinityPoint256;
    *(undefined4 *)((int)param_3 + 0x24) = _r_ke_msg_send;
    *(undefined4 *)((int)param_3 + 0x28) = _r_assert_err;
    memcpy(__s,&ecc_Jacobian_InfinityPoint256,0x22);
    *(undefined4 *)((int)param_3 + 0x50) = _DebugE256PublicKey_x;
    __src = &ecc_Jacobian_InfinityPoint256;
    *(undefined4 *)((int)param_3 + 0x54) = _DebugE256PublicKey_y;
  }
  memcpy((void *)((int)param_3 + 0x58),__src,0x22);
  *(undefined4 *)((int)param_3 + 0x7c) = *(undefined4 *)(param_2 + 0x7c);
  uVar3 = *(undefined4 *)(param_2 + 0x80);
_L189:
  *(undefined4 *)((int)param_3 + 0x80) = uVar3;
  return 0;
}

