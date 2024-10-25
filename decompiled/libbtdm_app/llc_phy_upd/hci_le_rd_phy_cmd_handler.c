/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc_phy_upd.o -> hci_le_rd_phy_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_rd_phy_cmd_handler(uint param_1,undefined2 *param_2)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 uVar3;
  
  puVar1 = (undefined1 *)
           (**(code **)(_r_modules_funcs_p + 200))
                     (0x1101,*param_2,6,*(code **)(_r_modules_funcs_p + 200));
  iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  uVar3 = 0xc;
  if (((param_1 < *(byte *)(iVar2 + 0xd)) && (iVar2 = *(int *)(&llc_env + param_1 * 4), iVar2 != 0))
     && ((*(byte *)(iVar2 + 0x44) & 3) != 3)) {
    uVar3 = 0;
    puVar1[5] = *(undefined1 *)(iVar2 + 0x1d);
    puVar1[4] = *(undefined1 *)(iVar2 + 0x1c);
  }
  *puVar1 = uVar3;
  *(undefined2 *)(puVar1 + 2) = *param_2;
  (**(code **)(_r_ip_funcs_p + 0x8c))(puVar1,*(code **)(_r_ip_funcs_p + 0x8c));
  return 0;
}

