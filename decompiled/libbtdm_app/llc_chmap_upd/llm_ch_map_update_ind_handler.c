/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc_chmap_upd.o -> llm_ch_map_update_ind_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 llm_ch_map_update_ind_handler(uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  uVar3 = param_1 >> 8;
  iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if ((((uVar3 < *(byte *)(iVar1 + 0xd)) && (iVar1 = *(int *)(&llc_env + uVar3 * 4), iVar1 != 0)) &&
      ((*(byte *)(iVar1 + 0x44) & 3) != 3)) && ((*(ushort *)(iVar1 + 0x42) & 0x100) == 0)) {
    puVar2 = (undefined4 *)
             (**(code **)(_r_modules_funcs_p + 200))
                       (0x10d,param_1,0x10,*(code **)(_r_modules_funcs_p + 200));
    *(undefined1 *)(puVar2 + 1) = 6;
    (**(code **)(_r_ip_funcs_p + 0x684))(uVar3,0,*(code **)(_r_ip_funcs_p + 0x684));
    *puVar2 = *(undefined4 *)(_r_ip_funcs_p + 0x618);
    (**(code **)(_r_modules_funcs_p + 0xe0))(puVar2,*(code **)(_r_modules_funcs_p + 0xe0));
    *(ushort *)(iVar1 + 0x42) = *(ushort *)(iVar1 + 0x42) | 0x100;
  }
  return 0;
}

