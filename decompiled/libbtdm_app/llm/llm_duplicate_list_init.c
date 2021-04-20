/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
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
                      (&DAT_000107dc,*(code **)(_r_modules_funcs_p + 0x50));
    if (iVar2 != 0) {
      llm_util_flush_list_part_0(&DAT_000107dc);
    }
    iVar2 = (**(code **)(_r_modules_funcs_p + 0x50))
                      (&le_scan_duplicate_option,*(code **)(_r_modules_funcs_p + 0x50));
    if (iVar2 != 0) {
      llm_util_flush_list_part_0(&le_scan_duplicate_option);
    }
    iVar2 = sdk_config_get_opts_ext();
    DAT_000107d4 = *(char *)(iVar2 + 4) == '\x01';
    iVar2 = sdk_config_get_opts_ext();
    DAT_000107d5 = *(undefined1 *)(iVar2 + 5);
    iVar2 = sdk_config_get_opts_ext();
    DAT_000107d6 = *(undefined2 *)(iVar2 + 6);
    iVar2 = sdk_config_get_opts_ext();
    DAT_000107d8 = *(undefined2 *)(iVar2 + 8);
    DAT_000107e4 = 0;
    DAT_000107e8 = 0;
  }
  if (DAT_000107d4 != '\0') {
    (**(code **)(_r_modules_funcs_p + 0x2c))(&DAT_000107dc,*(code **)(_r_modules_funcs_p + 0x2c));
  }
                    /* WARNING: Could not recover jumptable at 0x00010478. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0x2c))(&le_scan_duplicate_option);
  return;
}

