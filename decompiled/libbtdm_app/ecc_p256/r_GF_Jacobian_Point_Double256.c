/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> ecc_p256.o -> r_GF_Jacobian_Point_Double256
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
  undefined1 auStack_214 [44];
  undefined1 auStack_1e8 [44];
  undefined1 auStack_1bc [44];
  undefined1 auStack_190 [44];
  undefined1 auStack_164 [44];
  undefined1 auStack_138 [44];
  undefined1 auStack_10c [44];
  undefined1 auStack_e0 [44];
  undefined1 auStack_b4 [44];
  undefined1 auStack_88 [44];
  undefined1 auStack_5c [56];
  
  iVar2 = param_1 + 0x2c;
  iVar3 = param_1 + 0x58;
  if (((*(uint *)(param_1 + 0x50) < 2) && (*(short *)(param_1 + 0x4c) == 0)) ||
     ((iVar1 = (**(code **)(_r_modules_funcs_p + 0x3a4))
                         (param_1,&ecc_Jacobian_InfinityPoint256,
                          *(code **)(_r_modules_funcs_p + 0x3a4)), iVar1 == 0 &&
      ((iVar1 = (**(code **)(_r_modules_funcs_p + 0x3a4))
                          (iVar2,&ecc_Jacobian_InfinityPoint256,
                           *(code **)(_r_modules_funcs_p + 0x3a4)), iVar1 == 0 &&
       (iVar1 = (**(code **)(_r_modules_funcs_p + 0x3a4))
                          (iVar3,&ecc_Jacobian_InfinityPoint256,
                           *(code **)(_r_modules_funcs_p + 0x3a4)), iVar1 == 0)))))) {
    memcpy(param_2,&ecc_Jacobian_InfinityPoint256,0x22);
    *(undefined4 *)((int)param_2 + 0x24) = _DebugE256PublicKey_x;
    *(undefined4 *)((int)param_2 + 0x28) = _DebugE256PublicKey_y;
    memcpy((void *)((int)param_2 + 0x2c),&ecc_Jacobian_InfinityPoint256,0x22);
    *(undefined4 *)((int)param_2 + 0x50) = _DAT_00013068;
    *(undefined4 *)((int)param_2 + 0x54) = _DAT_0001306c;
    memcpy((void *)((int)param_2 + 0x58),&ecc_Jacobian_InfinityPoint256,0x22);
    *(undefined4 *)((int)param_2 + 0x7c) = _DAT_00013094;
    *(undefined4 *)((int)param_2 + 0x80) = _DAT_00013098;
  }
  else {
    (**(code **)(_r_modules_funcs_p + 0x354))
              (param_1,iVar3,auStack_b4,*(code **)(_r_modules_funcs_p + 0x354));
    (**(code **)(_r_modules_funcs_p + 0x3b0))
              (param_1,iVar3,auStack_88,*(code **)(_r_modules_funcs_p + 0x3b0));
    (**(code **)(_r_modules_funcs_p + 0x39c))
              (auStack_b4,auStack_88,auStack_5c,*(code **)(_r_modules_funcs_p + 0x39c));
    (**(code **)(_r_modules_funcs_p + 0x398))
              (auStack_5c,3,auStack_214,*(code **)(_r_modules_funcs_p + 0x398));
    (**(code **)(_r_modules_funcs_p + 0x39c))
              (iVar2,iVar3,auStack_1e8,*(code **)(_r_modules_funcs_p + 0x39c));
    (**(code **)(_r_modules_funcs_p + 0x39c))
              (iVar2,auStack_1e8,auStack_5c,*(code **)(_r_modules_funcs_p + 0x39c));
    (**(code **)(_r_modules_funcs_p + 0x39c))
              (param_1,auStack_5c,auStack_1bc,*(code **)(_r_modules_funcs_p + 0x39c));
    (**(code **)(_r_modules_funcs_p + 0x39c))
              (auStack_214,auStack_88,*(code **)(_r_modules_funcs_p + 0x39c));
    (**(code **)(_r_modules_funcs_p + 0x398))
              (auStack_1bc,8,auStack_5c,*(code **)(_r_modules_funcs_p + 0x398));
    (**(code **)(_r_modules_funcs_p + 0x3b0))
              (auStack_88,auStack_5c,auStack_190,*(code **)(_r_modules_funcs_p + 0x3b0));
    (**(code **)(_r_modules_funcs_p + 0x39c))
              (auStack_190,auStack_1e8,auStack_5c,*(code **)(_r_modules_funcs_p + 0x39c));
    (**(code **)(_r_modules_funcs_p + 0x398))
              (auStack_5c,2,param_2,*(code **)(_r_modules_funcs_p + 0x398));
    (**(code **)(_r_modules_funcs_p + 0x39c))
              (iVar2,iVar2,auStack_138,*(code **)(_r_modules_funcs_p + 0x39c));
    (**(code **)(_r_modules_funcs_p + 0x39c))
              (auStack_1e8,auStack_164,*(code **)(_r_modules_funcs_p + 0x39c));
    (**(code **)(_r_modules_funcs_p + 0x39c))
              (auStack_138,auStack_164,auStack_10c,*(code **)(_r_modules_funcs_p + 0x39c));
    (**(code **)(_r_modules_funcs_p + 0x398))
              (auStack_10c,8,auStack_e0,*(code **)(_r_modules_funcs_p + 0x398));
    (**(code **)(_r_modules_funcs_p + 0x398))
              (auStack_1bc,4,auStack_b4,*(code **)(_r_modules_funcs_p + 0x398));
    (**(code **)(_r_modules_funcs_p + 0x3b0))
              (auStack_b4,auStack_190,auStack_88,*(code **)(_r_modules_funcs_p + 0x3b0));
    (**(code **)(_r_modules_funcs_p + 0x39c))
              (auStack_214,auStack_88,auStack_5c,*(code **)(_r_modules_funcs_p + 0x39c));
    (**(code **)(_r_modules_funcs_p + 0x3b0))
              (auStack_5c,auStack_e0,(void *)((int)param_2 + 0x2c),
               *(code **)(_r_modules_funcs_p + 0x3b0));
    (**(code **)(_r_modules_funcs_p + 0x39c))
              (auStack_164,auStack_1e8,auStack_5c,*(code **)(_r_modules_funcs_p + 0x39c));
    (**(code **)(_r_modules_funcs_p + 0x398))
              (auStack_5c,8,(void *)((int)param_2 + 0x58),*(code **)(_r_modules_funcs_p + 0x398));
  }
  return 0;
}

