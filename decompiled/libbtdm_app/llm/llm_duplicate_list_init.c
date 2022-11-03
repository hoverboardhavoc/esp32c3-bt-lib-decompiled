/*
 * Last changed at upstream commit 976ca00e43905df9e910b400a9e17c311b085ce2
 * https://github.com/espressif/esp32c3-bt-lib/commit/976ca00e43905df9e910b400a9e17c311b085ce2
 * Upstream date: 2022-11-03 19:06:39 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(ef8a115a) - Added config to disable scan backoff - Fixed llm_scan.c assert at line 1485 during controller deinit if duplicate scan is not stopped - Call pll track in controller task
 * Source: libbtdm_app -> llm.o -> llm_duplicate_list_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void llm_duplicate_list_init(void)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = sdk_config_get_mask();
  if ((uVar1 & 1) != 0) {
    iVar2 = (**(code **)(_r_modules_funcs_p + 0x50))
                      (&DAT_00010800,*(code **)(_r_modules_funcs_p + 0x50));
    if (iVar2 != 0) {
      llm_util_flush_list_part_0(&DAT_00010800);
    }
    iVar2 = (**(code **)(_r_modules_funcs_p + 0x50))
                      (&le_scan_duplicate_option,*(code **)(_r_modules_funcs_p + 0x50));
    if (iVar2 != 0) {
      llm_util_flush_list_part_0(&le_scan_duplicate_option);
    }
    iVar2 = sdk_config_get_opts_ext();
    DAT_000107f8 = *(char *)(iVar2 + 4) == '\x01';
    iVar2 = sdk_config_get_opts_ext();
    DAT_000107f9 = *(undefined1 *)(iVar2 + 5);
    iVar2 = sdk_config_get_opts_ext();
    DAT_000107fa = *(undefined2 *)(iVar2 + 6);
    iVar2 = sdk_config_get_opts_ext();
    DAT_000107fc = *(undefined2 *)(iVar2 + 8);
    DAT_00010808 = 0;
    DAT_0001080c = 0;
  }
  if (DAT_000107f8 != '\0') {
    (**(code **)(_r_modules_funcs_p + 0x2c))(&DAT_00010800,*(code **)(_r_modules_funcs_p + 0x2c));
  }
                    /* WARNING: Could not recover jumptable at 0x00010478. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0x2c))(&le_scan_duplicate_option);
  return;
}

