/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> ecc_p256.o -> r_GF_Jacobian_Point_Addition256
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_GF_Jacobian_Point_Addition256(void *param_1,void *param_2,void *param_3)

{
  int iVar1;
  undefined4 uVar2;
  void *__s;
  void *__s_00;
  void *__src;
  void *__src_00;
  void *__src_01;
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
  __src_01 = (void *)((int)param_2 + 0x2c);
  __src = (void *)((int)param_2 + 0x58);
  __s_00 = (void *)((int)param_3 + 0x2c);
  memset(param_3,0,0x22);
  *(undefined4 *)((int)param_3 + 0x24) = 0;
  *(undefined4 *)((int)param_3 + 0x28) = 0;
  memset(__s_00,0,0x22);
  __s = (void *)((int)param_3 + 0x58);
  *(undefined4 *)((int)param_3 + 0x50) = 0;
  *(undefined4 *)((int)param_3 + 0x54) = 0;
  memset(__s,0,0x22);
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
  iVar1 = (**(code **)(_r_modules_funcs_p + 0x3a4))
                    (param_1,&ecc_Jacobian_InfinityPoint256,*(code **)(_r_modules_funcs_p + 0x3a4));
  if (((iVar1 == 0) &&
      (iVar1 = (**(code **)(_r_modules_funcs_p + 0x3a4))
                         (__src_02,&ecc_Jacobian_InfinityPoint256,
                          *(code **)(_r_modules_funcs_p + 0x3a4)), iVar1 == 0)) &&
     (iVar1 = (**(code **)(_r_modules_funcs_p + 0x3a4))
                        (__src_00,&ecc_Jacobian_InfinityPoint256,
                         *(code **)(_r_modules_funcs_p + 0x3a4)), iVar1 == 0)) {
    iVar1 = (**(code **)(_r_modules_funcs_p + 0x3a4))
                      (param_2,&ecc_Jacobian_InfinityPoint256,*(code **)(_r_modules_funcs_p + 0x3a4)
                      );
    if (((iVar1 != 0) ||
        (iVar1 = (**(code **)(_r_modules_funcs_p + 0x3a4))
                           (__src_01,&ecc_Jacobian_InfinityPoint256,
                            *(code **)(_r_modules_funcs_p + 0x3a4)), iVar1 != 0)) ||
       (iVar1 = (**(code **)(_r_modules_funcs_p + 0x3a4))
                          (__src,&ecc_Jacobian_InfinityPoint256,
                           *(code **)(_r_modules_funcs_p + 0x3a4)), iVar1 != 0)) {
      memcpy(param_3,param_2,0x22);
      *(undefined4 *)((int)param_3 + 0x24) = *(undefined4 *)((int)param_2 + 0x24);
      *(undefined4 *)((int)param_3 + 0x28) = *(undefined4 *)((int)param_2 + 0x28);
      memcpy(__s_00,__src_01,0x22);
      *(undefined4 *)((int)param_3 + 0x50) = *(undefined4 *)((int)param_2 + 0x50);
      *(undefined4 *)((int)param_3 + 0x54) = *(undefined4 *)((int)param_2 + 0x54);
      memcpy(__s,__src,0x22);
      *(undefined4 *)((int)param_3 + 0x7c) = *(undefined4 *)((int)param_2 + 0x7c);
      *(undefined4 *)((int)param_3 + 0x80) = *(undefined4 *)((int)param_2 + 0x80);
      return 0;
    }
    memcpy(param_3,&ecc_Jacobian_InfinityPoint256,0x22);
    *(undefined4 *)((int)param_3 + 0x24) = _DebugE256PublicKey_x;
    *(undefined4 *)((int)param_3 + 0x28) = _DebugE256PublicKey_y;
    memcpy(__s_00,&ecc_Jacobian_InfinityPoint256,0x22);
    *(undefined4 *)((int)param_3 + 0x50) = _DAT_00013068;
    *(undefined4 *)((int)param_3 + 0x54) = _DAT_0001306c;
  }
  else {
    iVar1 = (**(code **)(_r_modules_funcs_p + 0x3a4))
                      (param_2,&ecc_Jacobian_InfinityPoint256,*(code **)(_r_modules_funcs_p + 0x3a4)
                      );
    if (((iVar1 == 0) &&
        (iVar1 = (**(code **)(_r_modules_funcs_p + 0x3a4))
                           (__src_01,&ecc_Jacobian_InfinityPoint256,
                            *(code **)(_r_modules_funcs_p + 0x3a4)), iVar1 == 0)) &&
       (iVar1 = (**(code **)(_r_modules_funcs_p + 0x3a4))
                          (__src,&ecc_Jacobian_InfinityPoint256,
                           *(code **)(_r_modules_funcs_p + 0x3a4)), iVar1 == 0)) {
      memcpy(param_3,param_1,0x22);
      *(undefined4 *)((int)param_3 + 0x24) = *(undefined4 *)((int)param_1 + 0x24);
      *(undefined4 *)((int)param_3 + 0x28) = *(undefined4 *)((int)param_1 + 0x28);
      memcpy(__s_00,__src_02,0x22);
      *(undefined4 *)((int)param_3 + 0x50) = *(undefined4 *)((int)param_1 + 0x50);
      *(undefined4 *)((int)param_3 + 0x54) = *(undefined4 *)((int)param_1 + 0x54);
      memcpy(__s,__src_00,0x22);
      *(undefined4 *)((int)param_3 + 0x7c) = *(undefined4 *)((int)param_1 + 0x7c);
      uVar2 = *(undefined4 *)((int)param_1 + 0x80);
      goto _L176;
    }
    iVar1 = (**(code **)(_r_modules_funcs_p + 0x3a4))
                      (param_2,param_1,*(code **)(_r_modules_funcs_p + 0x3a4));
    if ((iVar1 != 0) ||
       ((iVar1 = (**(code **)(_r_modules_funcs_p + 0x3a4))
                           (__src_01,__src_02,*(code **)(_r_modules_funcs_p + 0x3a4)), iVar1 == 0 &&
        ((1 < *(uint *)((int)param_2 + 0x50) || (*(short *)((int)param_2 + 0x4c) != 0)))))) {
      (**(code **)(_r_modules_funcs_p + 0x39c))
                (__src_01,__src_00,auStack_2d4,*(code **)(_r_modules_funcs_p + 0x39c));
      (**(code **)(_r_modules_funcs_p + 0x39c))
                (__src_02,__src,auStack_2a8,*(code **)(_r_modules_funcs_p + 0x39c));
      (**(code **)(_r_modules_funcs_p + 0x39c))
                (param_2,__src_00,auStack_27c,*(code **)(_r_modules_funcs_p + 0x39c));
      (**(code **)(_r_modules_funcs_p + 0x39c))
                (param_1,__src,auStack_250,*(code **)(_r_modules_funcs_p + 0x39c));
      iVar1 = (**(code **)(_r_modules_funcs_p + 0x3a4))
                        (auStack_27c,auStack_250,*(code **)(_r_modules_funcs_p + 0x3a4));
      if (iVar1 != 0) {
        (**(code **)(_r_modules_funcs_p + 0x3b0))
                  (auStack_2d4,auStack_2a8,auStack_224,*(code **)(_r_modules_funcs_p + 0x3b0));
        (**(code **)(_r_modules_funcs_p + 0x3b0))
                  (auStack_27c,auStack_250,auStack_1f8,*(code **)(_r_modules_funcs_p + 0x3b0));
        (**(code **)(_r_modules_funcs_p + 0x39c))
                  (__src_00,__src,auStack_1a0,*(code **)(_r_modules_funcs_p + 0x39c));
        memset(auStack_c4,0,0x22);
        uStack_a0 = 0;
        uStack_9c = 0;
        memset(auStack_98,0,0x22);
        uStack_74 = 0;
        uStack_70 = 0;
        memset(auStack_6c,0,0x22);
        uStack_48 = 0;
        uStack_44 = 0;
        (**(code **)(_r_modules_funcs_p + 0x39c))
                  (auStack_1f8,auStack_174,*(code **)(_r_modules_funcs_p + 0x39c));
        (**(code **)(_r_modules_funcs_p + 0x39c))
                  (auStack_174,auStack_1f8,auStack_148,*(code **)(_r_modules_funcs_p + 0x39c));
        (**(code **)(_r_modules_funcs_p + 0x39c))
                  (auStack_224,auStack_11c,*(code **)(_r_modules_funcs_p + 0x39c));
        (**(code **)(_r_modules_funcs_p + 0x39c))
                  (auStack_174,auStack_250,auStack_f0,*(code **)(_r_modules_funcs_p + 0x39c));
        (**(code **)(_r_modules_funcs_p + 0x398))
                  (auStack_f0,2,auStack_6c,*(code **)(_r_modules_funcs_p + 0x398));
        (**(code **)(_r_modules_funcs_p + 0x39c))
                  (auStack_11c,auStack_1a0,auStack_c4,*(code **)(_r_modules_funcs_p + 0x39c));
        (**(code **)(_r_modules_funcs_p + 0x3b0))
                  (auStack_c4,auStack_148,auStack_98,*(code **)(_r_modules_funcs_p + 0x3b0));
        (**(code **)(_r_modules_funcs_p + 0x3b0))
                  (auStack_98,auStack_6c,auStack_1cc,*(code **)(_r_modules_funcs_p + 0x3b0));
        (**(code **)(_r_modules_funcs_p + 0x39c))
                  (auStack_1f8,auStack_1cc,param_3,*(code **)(_r_modules_funcs_p + 0x39c));
        memset(auStack_c4,0,0x22);
        uStack_a0 = 0;
        uStack_9c = 0;
        memset(auStack_98,0,0x22);
        uStack_74 = 0;
        uStack_70 = 0;
        memset(auStack_6c,0,0x22);
        uStack_48 = 0;
        uStack_44 = 0;
        (**(code **)(_r_modules_funcs_p + 0x3b0))
                  (auStack_f0,auStack_1cc,auStack_c4,*(code **)(_r_modules_funcs_p + 0x3b0));
        (**(code **)(_r_modules_funcs_p + 0x39c))
                  (auStack_224,auStack_c4,auStack_98,*(code **)(_r_modules_funcs_p + 0x39c));
        (**(code **)(_r_modules_funcs_p + 0x39c))
                  (auStack_148,auStack_2a8,auStack_6c,*(code **)(_r_modules_funcs_p + 0x39c));
        (**(code **)(_r_modules_funcs_p + 0x3b0))
                  (auStack_98,auStack_6c,__s_00,*(code **)(_r_modules_funcs_p + 0x3b0));
        (**(code **)(_r_modules_funcs_p + 0x39c))
                  (auStack_148,auStack_1a0,__s,*(code **)(_r_modules_funcs_p + 0x39c));
        return 1;
      }
      iVar1 = (**(code **)(_r_modules_funcs_p + 0x3a4))
                        (auStack_2d4,auStack_2a8,*(code **)(_r_modules_funcs_p + 0x3a4));
      if (iVar1 == 0) {
        (**(code **)(_r_modules_funcs_p + 0x38c))
                  (param_1,param_3,*(code **)(_r_modules_funcs_p + 0x38c));
        return 0;
      }
    }
    memcpy(param_3,&ecc_Jacobian_InfinityPoint256,0x22);
    *(undefined4 *)((int)param_3 + 0x24) = _DebugE256PublicKey_x;
    *(undefined4 *)((int)param_3 + 0x28) = _DebugE256PublicKey_y;
    memcpy(__s_00,&ecc_Jacobian_InfinityPoint256,0x22);
    *(undefined4 *)((int)param_3 + 0x50) = _DAT_00013068;
    *(undefined4 *)((int)param_3 + 0x54) = _DAT_0001306c;
  }
  memcpy(__s,&ecc_Jacobian_InfinityPoint256,0x22);
  *(undefined4 *)((int)param_3 + 0x7c) = _DAT_00013094;
  uVar2 = _DAT_00013098;
_L176:
  *(undefined4 *)((int)param_3 + 0x80) = uVar2;
  return 0;
}

