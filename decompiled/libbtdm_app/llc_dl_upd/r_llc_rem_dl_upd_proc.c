/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc_dl_upd.o -> r_llc_rem_dl_upd_proc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_rem_dl_upd_proc(uint param_1,uint param_2,uint param_3,uint param_4,uint param_5)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  code *pcVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  iVar5 = *(int *)(&llc_env + param_1 * 4);
  uVar6 = (uint)*(ushort *)(iVar5 + 0x20);
  if (param_5 < *(ushort *)(iVar5 + 0x20)) {
    uVar6 = param_5;
  }
  uVar7 = uVar6 & 0xffff;
  uVar3 = (uint)*(ushort *)(iVar5 + 0x22);
  if (param_4 < *(ushort *)(iVar5 + 0x22)) {
    uVar3 = param_4;
  }
  if (0xfb < param_3) {
    param_3 = 0xfb;
  }
  uVar8 = param_3 & 0xffff;
  if (0x4290 < param_2) {
    param_2 = 0x4290;
  }
  param_2 = param_2 & 0xffff;
  if (*(char *)(iVar5 + 0x1c) == '\x03') {
    if (uVar3 < 0xa90) {
      uVar3 = 0xa90;
    }
    iVar2 = (**(code **)(_r_modules_funcs_p + 0x188))(*(code **)(_r_modules_funcs_p + 0x188));
    uVar1 = uVar3;
    if (iVar2 != 0) {
      iVar2 = (**(code **)(_r_modules_funcs_p + 0x188))(*(code **)(_r_modules_funcs_p + 0x188));
      if (iVar2 == 0) {
        uVar1 = 0xa90;
      }
      else {
        uVar1 = (uint)*(ushort *)(*(int *)(_bt_rf_coex_cfg_p + 0x44) + 2);
      }
      if (uVar1 < 0xa90) {
        uVar1 = 0xa90;
      }
      if (uVar3 < uVar1) {
        uVar1 = uVar3;
      }
    }
    uVar1 = uVar1 & 0xffff;
  }
  else {
    uVar1 = uVar3 & 0xffff;
    if (*(char *)(iVar5 + 0x1d) != '\x03') {
      if (((((*(ushort *)(iVar5 + 0x42) & 0x80) == 0) ||
           (iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38)),
           *(byte *)(iVar2 + 0xd) <= param_1)) || (*(int *)(&llc_env + param_1 * 4) == 0)) ||
         (((int)(uint)*(byte *)(*(int *)(&llc_env + param_1 * 4) + 0x31) >> 3 & 1U) == 0)) {
        if (0x848 < uVar3) {
          uVar3 = 0x848;
        }
        uVar1 = uVar3 & 0xffff;
        if (0x848 < param_2) {
          param_2 = 0x848;
        }
      }
      goto _L73;
    }
  }
  if (*(char *)(iVar5 + 0x1d) == '\x03') {
    uVar3 = param_2;
    if (param_2 < 0xa90) {
      uVar3 = 0xa90;
    }
    iVar2 = (**(code **)(_r_modules_funcs_p + 0x188))(*(code **)(_r_modules_funcs_p + 0x188));
    param_2 = uVar3;
    if (iVar2 != 0) {
      iVar2 = (**(code **)(_r_modules_funcs_p + 0x188))(*(code **)(_r_modules_funcs_p + 0x188));
      if (iVar2 == 0) {
        param_2 = 0xa90;
      }
      else {
        param_2 = (uint)**(ushort **)(_bt_rf_coex_cfg_p + 0x44);
      }
      if (param_2 < 0xa90) {
        param_2 = 0xa90;
      }
      if (uVar3 < param_2) {
        param_2 = uVar3;
      }
    }
  }
_L73:
  if (((*(ushort *)(iVar5 + 0x16) != uVar8) || (*(ushort *)(iVar5 + 0x14) != uVar7)) ||
     ((*(ushort *)(iVar5 + 0x1a) != param_2 || (*(ushort *)(iVar5 + 0x18) != uVar1)))) {
    pcVar4 = *(code **)(_r_ip_funcs_p + 0x32c);
    *(short *)(iVar5 + 0x16) = (short)param_3;
    *(short *)(iVar5 + 0x14) = (short)uVar6;
    *(short *)(iVar5 + 0x1a) = (short)param_2;
    *(short *)(iVar5 + 0x18) = (short)uVar1;
    (*pcVar4)(param_1,uVar1,uVar7,param_2,uVar8,pcVar4);
    (**(code **)(_r_ip_funcs_p + 0x5d0))
              (param_1,0,uVar1,uVar7,param_2,uVar8,*(code **)(_r_ip_funcs_p + 0x5d0));
  }
  (**(code **)(_r_ip_funcs_p + 0x5b4))(param_1,&stack0xffffffe4,0,*(code **)(_r_ip_funcs_p + 0x5b4))
  ;
  return;
}

