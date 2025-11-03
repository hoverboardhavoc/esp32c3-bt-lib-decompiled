/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_start_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int r_lld_con_start_eco(uint param_1,int param_2)

{
  int iVar1;
  
  _DAT_000150f8 = r_lld_read_clock();
  *(undefined2 *)(&DAT_000150b0 + (param_1 + 0x10) * 2) = 0;
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

