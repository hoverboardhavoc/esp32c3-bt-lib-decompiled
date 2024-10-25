/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_enc_key_load
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_enc_key_load(int param_1,int param_2,undefined2 *param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  int iVar7;
  
  if (*(int *)(&lld_con_env + param_1 * 4) != 0) {
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar5 = _r_plf_funcs_p;
    param_1 = param_1 * 0x5a;
    iVar7 = 0;
    *(undefined2 *)(iVar4 + param_1 + 0x44) = 0;
    iVar4 = (**(code **)(iVar5 + 0xbc))(0x400,*(code **)(iVar5 + 0xbc));
    iVar5 = _r_plf_funcs_p;
    *(undefined2 *)(iVar4 + param_1 + 0x46) = 0;
    iVar4 = (**(code **)(iVar5 + 0xbc))(0x400,*(code **)(iVar5 + 0xbc));
    iVar5 = _r_plf_funcs_p;
    *(undefined2 *)(iVar4 + param_1 + 0x48) = 0;
    iVar4 = (**(code **)(iVar5 + 0xbc))(0x400,*(code **)(iVar5 + 0xbc));
    iVar5 = _r_plf_funcs_p;
    *(undefined2 *)(iVar4 + param_1 + 0x4a) = 0;
    iVar4 = (**(code **)(iVar5 + 0xbc))(0x400,*(code **)(iVar5 + 0xbc));
    iVar5 = _r_plf_funcs_p;
    *(undefined2 *)(iVar4 + param_1 + 0x4c) = 0;
    iVar5 = (**(code **)(iVar5 + 0xbc))(0x400,*(code **)(iVar5 + 0xbc));
    *(undefined2 *)(iVar5 + param_1 + 0x4e) = 0;
    do {
      uVar3 = *param_3;
      param_3 = param_3 + 1;
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar5 + param_1 + 0x3c + iVar7) = uVar3;
      iVar7 = iVar7 + 2;
    } while (iVar7 != 8);
    iVar5 = 0;
    do {
      puVar6 = (undefined1 *)((0xfU - iVar5 & 0xff) + param_2);
      uVar1 = puVar6[-1];
      uVar2 = *puVar6;
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar4 + param_1 + 0x2c + iVar5) = CONCAT11(uVar1,uVar2);
      iVar5 = iVar5 + 2;
    } while (iVar5 != 0x10);
    return;
  }
  return;
}

