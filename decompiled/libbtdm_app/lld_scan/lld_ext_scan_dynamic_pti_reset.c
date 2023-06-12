/*
 * Last changed at upstream commit b438f60a295183e7c67eb42ae05f4580f4b1ced0
 * https://github.com/espressif/esp32c3-bt-lib/commit/b438f60a295183e7c67eb42ae05f4580f4b1ced0
 * Upstream date: 2023-06-12 21:42:40 +0800
 * Upstream subject: update libbtdm_app.a for ESP32C3 and ESP32S3(963cad48)
 * Source: libbtdm_app -> lld_scan.o -> lld_ext_scan_dynamic_pti_reset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void lld_ext_scan_dynamic_pti_reset(int param_1)

{
  if (((param_1 != 0) && (*(char *)(_lld_scan_env + 0x17) != '\0')) &&
     (*(char *)(param_1 + 0x3d) == '\0')) {
                    /* WARNING: Could not recover jumptable at 0x00010024. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_ip_funcs_p + 0x3d8))(1);
    return;
  }
  return;
}

