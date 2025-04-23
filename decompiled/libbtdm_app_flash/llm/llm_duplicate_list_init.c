/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llm.o -> llm_duplicate_list_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void llm_duplicate_list_init(void)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = sdk_config_get_mask();
  if ((uVar1 & 1) != 0) {
    iVar2 = r_co_list_size(&le_scan_duplicate_option);
    if (iVar2 != 0) {
      llm_util_flush_list_part_0(&le_scan_duplicate_option);
    }
    iVar2 = r_co_list_size(&le_scan_duplicate_option);
    if (iVar2 != 0) {
      llm_util_flush_list_part_0(&le_scan_duplicate_option);
    }
    iVar2 = r_sdk_config_get_opts_ext();
    DAT_00011388 = *(char *)(iVar2 + 4) == '\x01';
    iVar2 = r_sdk_config_get_opts_ext();
    DAT_00011389 = *(undefined1 *)(iVar2 + 5);
    iVar2 = r_sdk_config_get_opts_ext();
    DAT_0001138a = *(undefined2 *)(iVar2 + 6);
    iVar2 = r_sdk_config_get_opts_ext();
    DAT_0001138c = *(undefined2 *)(iVar2 + 8);
    DAT_00011398 = 0;
    DAT_0001139c = 0;
  }
  if (DAT_00011388 != '\0') {
    r_co_list_init(&le_scan_duplicate_option);
  }
  r_co_list_init(&le_scan_duplicate_option);
  return;
}

