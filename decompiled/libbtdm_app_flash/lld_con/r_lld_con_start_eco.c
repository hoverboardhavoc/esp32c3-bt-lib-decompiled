/*
 * Last changed at upstream commit f23a340e82d6a4be40f83214385a98c5bd30ccdd
 * https://github.com/espressif/esp32c3-bt-lib/commit/f23a340e82d6a4be40f83214385a98c5bd30ccdd
 * Upstream date: 2025-04-03 18:07:15 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(a684dd5)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_start_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int r_lld_con_start_eco(uint param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  DAT_000150a0 = r_lld_read_clock();
  *(undefined2 *)(&DAT_00015058 + (param_1 + 0x10) * 2) = 0;
  r_lld_con_update_terminte_info_init(param_1);
  *(undefined2 *)(&DAT_0001505c + (param_1 + 0x18) * 2) = 0;
  iVar1 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar1 + 0x18) == '\0') {
    *(undefined1 *)(param_2 + 0x26) = 0;
  }
  iVar1 = r_lld_con_start(param_1,param_2);
  if ((iVar1 == 0) && (*(int *)(&lld_con_env + param_1 * 4) != 0)) {
    *(undefined2 *)(*(int *)(&lld_con_env + param_1 * 4) + 0x98) = 0xffff;
  }
  iVar2 = r_sdk_config_get_opts_ext();
  if ((*(uint *)(iVar2 + 0x28) & 0x20) != 0) {
    iVar2 = r_sdk_config_get_opts_ext();
    if (*(byte *)(iVar2 + 0x2c) < 3) {
      r_ble_log_internal_x1
                (0x40030000,iVar1 << 0x10 | param_1 | (uint)*(byte *)(param_2 + 0x24) << 8);
    }
  }
  return iVar1;
}

