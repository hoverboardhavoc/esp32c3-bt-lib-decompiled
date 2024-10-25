/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc_con_upd.o -> r_llc_pref_param_compute_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_pref_param_compute_eco(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined2 uVar5;
  uint uVar6;
  uint uStack_50;
  uint uStack_4c;
  uint uStack_48;
  undefined2 uStack_44;
  int iStack_40;
  uint uStack_3c;
  uint uStack_38;
  uint uStack_34;
  undefined2 uStack_30;
  char cStack_2e;
  byte bStack_2d;
  uint uStack_2c;
  uint uStack_28;
  
  if (((((*(uint *)(param_2 + 0x2c) & 0xffff00) != 0) &&
       (uVar3 = (**(code **)(_r_ip_funcs_p + 0x7c8))(*(code **)(_r_ip_funcs_p + 0x7c8)), uVar3 < 2))
      && (*(short *)(param_2 + 0x16) != -1)) &&
     (iVar4 = (**(code **)(_r_ip_funcs_p + 0x680))(param_2,*(code **)(_r_ip_funcs_p + 0x680)),
     iVar4 == 2)) {
    *(undefined2 *)(param_2 + 0x2a) = *(undefined2 *)(param_2 + 0x16);
    *(undefined2 *)(param_2 + 0x28) = *(undefined2 *)(param_2 + 8);
    return;
  }
  iVar4 = *(int *)(&llc_env + param_1 * 4);
  uVar3 = (**(code **)(_r_ip_funcs_p + 0x374))(*(code **)(_r_ip_funcs_p + 0x374));
  iStack_40 = (uint)*(ushort *)(param_2 + 8) << 1;
  uStack_38 = (uint)*(ushort *)(param_2 + 0x10);
  uVar6 = (uint)*(ushort *)(param_2 + 10) * 2;
  if (uStack_38 < 2) {
    uStack_38 = 2;
  }
  uStack_34 = (uint)*(ushort *)(param_2 + 0x12);
  if (uStack_34 < 2) {
    uStack_34 = 2;
  }
  uStack_30 = (undefined2)param_1;
  cStack_2e = *(char *)(param_2 + 0x27) << 1;
  *(undefined1 *)(param_2 + 0x27) = 1;
  uStack_3c = uVar6;
  if ((*(ushort *)(iVar4 + 0x42) & 1) == 0) {
    if (*(ushort *)(param_2 + 10) == 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"llc_con_upd.c",0x94,*(code **)(_r_plf_funcs_p + 8));
    }
    uVar3 = ((uVar6 - 1) + uVar3) % uVar6;
    uStack_38 = uStack_38 + 3;
    uStack_34 = uStack_34 + 3;
  }
  bStack_2d = (byte)uVar3 & 1;
  if (((*(char *)(param_2 + 0x2d) == '\0') && (*(char *)(param_2 + 0x2e) == '\0')) &&
     (uVar1 = *(ushort *)(param_2 + 0x16), (uVar1 - 1 & 0xffff) < 0xfffe)) {
    uStack_4c = uStack_38;
    uVar6 = (uint)*(ushort *)(param_2 + 8) << 1;
    uStack_44 = uStack_30;
    uStack_50 = uVar6;
    if (*(ushort *)(param_2 + 8) == 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"llc_con_upd.c",0x94,*(code **)(_r_plf_funcs_p + 8));
    }
    uStack_48 = ((uint)uVar1 * 2 + uVar3) % uVar6;
    iVar2 = (**(code **)(_r_ip_funcs_p + 0x6d8))(&uStack_50,*(code **)(_r_ip_funcs_p + 0x6d8));
    if (iVar2 != 0) goto _L44;
    *(undefined2 *)(param_2 + 0x2a) = *(undefined2 *)(param_2 + 0x16);
  }
  else {
_L44:
    iVar2 = (**(code **)(_r_ip_funcs_p + 0x6f8))(&iStack_40,*(code **)(_r_ip_funcs_p + 0x6f8));
    uVar3 = uStack_2c;
    if (iVar2 != 0) {
      *(undefined2 *)(param_2 + 0x2a) = 0;
      uVar5 = *(undefined2 *)(param_2 + 10);
      goto _L52;
    }
    if ((*(ushort *)(iVar4 + 0x42) & 1) == 0) {
      if (uStack_2c == 0) {
        (**(code **)(_r_plf_funcs_p + 8))("llc_con_upd.c",0x94,*(code **)(_r_plf_funcs_p + 8));
      }
      uStack_28 = (uStack_28 + 1) % uVar3;
    }
    iVar4 = (**(code **)(_r_ip_funcs_p + 0x318))
                      (param_1,*(undefined2 *)(param_2 + 0x14),uStack_2c >> 1 & 0xffff,
                       uStack_28 & 0xffff,0,*(code **)(_r_ip_funcs_p + 0x318));
    *(short *)(param_2 + 0x2a) = (short)(iVar4 / 0x4e2);
    uStack_50 = uStack_2c;
  }
  uVar5 = (undefined2)(uStack_50 >> 1);
_L52:
  *(undefined2 *)(param_2 + 0x28) = uVar5;
  return;
}

