/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
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
  
  _DAT_00015694 = r_lld_read_clock();
  *(undefined2 *)(&DAT_0001564c + (param_1 + 0x10) * 2) = 0;
  r_lld_con_update_terminte_info_init(param_1);
  r_lld_con_llcp_ind_info_clear(param_1);
  iVar1 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar1 + 0x18) == '\0') {
    *(undefined1 *)(param_2 + 0x26) = 0;
  }
  iVar1 = r_lld_con_start(param_1,param_2);
  if (iVar1 == 0) {
    if (*(int *)(&lld_con_env + param_1 * 4) != 0) {
      *(undefined2 *)(*(int *)(&lld_con_env + param_1 * 4) + 0x98) = 0xffff;
      *(undefined4 *)(lld_con_fake_rx + param_1 * 4) = 0;
    }
  }
  r_ble_log_internal_x1(0x400300fb,iVar1 << 0x10 | (uint)*(byte *)(param_2 + 0x24) << 8 | param_1);
  return iVar1;
}

