/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
    iVar2 = r_co_list_size(0x11360);
    if (iVar2 != 0) {
      llm_util_flush_list_part_0(0x11360);
    }
    iVar2 = r_co_list_size(le_scan_duplicate_option);
    if (iVar2 != 0) {
      llm_util_flush_list_part_0(le_scan_duplicate_option);
    }
    iVar2 = r_sdk_config_get_opts_ext();
    le_scan_duplicate_option[8] = *(char *)(iVar2 + 4) == '\x01';
    iVar2 = r_sdk_config_get_opts_ext();
    le_scan_duplicate_option[9] = *(undefined1 *)(iVar2 + 5);
    iVar2 = r_sdk_config_get_opts_ext();
    le_scan_duplicate_option._10_2_ = *(undefined2 *)(iVar2 + 6);
    iVar2 = r_sdk_config_get_opts_ext();
    le_scan_duplicate_option._12_2_ = *(undefined2 *)(iVar2 + 8);
    le_scan_duplicate_option._24_4_ = 0;
    le_scan_duplicate_option._28_4_ = 0;
  }
  if (le_scan_duplicate_option[8] != '\0') {
    r_co_list_init(0x11360);
  }
  r_co_list_init(le_scan_duplicate_option);
  return;
}

