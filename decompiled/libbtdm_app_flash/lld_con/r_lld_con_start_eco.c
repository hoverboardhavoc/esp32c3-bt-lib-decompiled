/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_start_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_con_start_eco(int param_1,int param_2)

{
  int iVar1;
  
  DAT_000149f4 = r_lld_read_clock();
  *(undefined2 *)(&DAT_000149ac + (param_1 + 0x10) * 2) = 0;
  r_lld_con_update_terminte_info_init(param_1);
  *(undefined2 *)(&DAT_000149b0 + (param_1 + 0x18) * 2) = 0;
  iVar1 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar1 + 0x18) == '\0') {
    *(undefined1 *)(param_2 + 0x26) = 0;
  }
  iVar1 = r_lld_con_start(param_1);
  if ((iVar1 == 0) && (*(int *)(&lld_con_env + param_1 * 4) != 0)) {
    *(undefined2 *)(*(int *)(&lld_con_env + param_1 * 4) + 0x98) = 0xffff;
  }
  return;
}

