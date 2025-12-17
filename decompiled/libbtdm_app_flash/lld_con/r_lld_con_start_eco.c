/*
 * Last changed at upstream commit 9b50531537e755792ac827d00d233eab499a0b37
 * https://github.com/espressif/esp32c3-bt-lib/commit/9b50531537e755792ac827d00d233eab499a0b37
 * Upstream date: 2025-12-17 10:51:37 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(5106725)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_start_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int r_lld_con_start_eco(uint param_1,int param_2)

{
  int iVar1;
  
  DAT_000150c8 = r_lld_read_clock();
  *(undefined2 *)(&DAT_00015080 + (param_1 + 0x10) * 2) = 0;
  r_lld_con_update_terminte_info_init(param_1);
  r_lld_con_llcp_ind_info_clear(param_1);
  iVar1 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar1 + 0x18) == '\0') {
    *(undefined1 *)(param_2 + 0x26) = 0;
  }
  iVar1 = r_lld_con_start(param_1,param_2);
  if ((iVar1 == 0) && (*(int *)(&lld_con_env + param_1 * 4) != 0)) {
    *(undefined2 *)(*(int *)(&lld_con_env + param_1 * 4) + 0x98) = 0xffff;
  }
  r_ble_log_internal_x1(0x40030078,iVar1 << 0x10 | (uint)*(byte *)(param_2 + 0x24) << 8 | param_1);
  return iVar1;
}

