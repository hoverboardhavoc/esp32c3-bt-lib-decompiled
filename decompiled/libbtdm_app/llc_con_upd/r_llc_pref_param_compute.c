/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc_con_upd.o -> r_llc_pref_param_compute
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_pref_param_compute(int param_1,int param_2)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  undefined2 uVar4;
  uint uVar5;
  int iVar6;
  uint local_50;
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
  
  iVar6 = *(int *)(&llc_env + param_1 * 4);
  uVar2 = (**(code **)(_r_ip_funcs_p + 0x374))(*(code **)(_r_ip_funcs_p + 0x374));
  iStack_40 = (uint)*(ushort *)(param_2 + 8) << 1;
  uStack_38 = (uint)*(ushort *)(param_2 + 0x10);
  uVar5 = (uint)*(ushort *)(param_2 + 10) * 2;
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
  uStack_3c = uVar5;
  if ((*(ushort *)(iVar6 + 0x42) & 1) == 0) {
    if (*(ushort *)(param_2 + 10) == 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"llc_con_upd.c",0x94,*(code **)(_r_plf_funcs_p + 8));
    }
    uVar2 = ((uVar5 - 1) + uVar2) % uVar5;
    uStack_38 = uStack_38 + 3;
    uStack_34 = uStack_34 + 3;
  }
  bStack_2d = (byte)uVar2 & 1;
  if (((*(char *)(param_2 + 0x2d) == '\0') && (*(char *)(param_2 + 0x2e) == '\0')) &&
     (uVar1 = *(ushort *)(param_2 + 0x16), (uVar1 - 1 & 0xffff) < 0xfffe)) {
    uStack_4c = uStack_38;
    uVar5 = (uint)*(ushort *)(param_2 + 8) << 1;
    uStack_44 = uStack_30;
    local_50 = uVar5;
    if (*(ushort *)(param_2 + 8) == 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"llc_con_upd.c",0x94,*(code **)(_r_plf_funcs_p + 8));
    }
    uStack_48 = ((uint)uVar1 * 2 + uVar2) % uVar5;
    iVar3 = (**(code **)(_r_ip_funcs_p + 0x6d8))(&local_50,*(code **)(_r_ip_funcs_p + 0x6d8));
    if (iVar3 != 0) goto _L44;
    *(undefined2 *)(param_2 + 0x2a) = *(undefined2 *)(param_2 + 0x16);
  }
  else {
_L44:
    iVar3 = (**(code **)(_r_ip_funcs_p + 0x6f8))(&iStack_40,*(code **)(_r_ip_funcs_p + 0x6f8));
    uVar2 = uStack_2c;
    if (iVar3 != 0) {
      *(undefined2 *)(param_2 + 0x2a) = 0;
      uVar4 = *(undefined2 *)(param_2 + 10);
      goto _L52;
    }
    if ((*(ushort *)(iVar6 + 0x42) & 1) == 0) {
      if (uStack_2c == 0) {
        (**(code **)(_r_plf_funcs_p + 8))("llc_con_upd.c",0x94,*(code **)(_r_plf_funcs_p + 8));
      }
      uStack_28 = (uStack_28 + 1) % uVar2;
    }
    iVar6 = (**(code **)(_r_ip_funcs_p + 0x318))
                      (param_1,*(undefined2 *)(param_2 + 0x14),uStack_2c >> 1 & 0xffff,
                       uStack_28 & 0xffff,0,*(code **)(_r_ip_funcs_p + 0x318));
    *(short *)(param_2 + 0x2a) = (short)(iVar6 / 0x4e2);
    local_50 = uStack_2c;
  }
  uVar4 = (undefined2)(local_50 >> 1);
_L52:
  *(undefined2 *)(param_2 + 0x28) = uVar4;
  return;
}

