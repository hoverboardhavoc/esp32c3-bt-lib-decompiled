/*
 * Last changed at upstream commit b438f60a295183e7c67eb42ae05f4580f4b1ced0
 * https://github.com/espressif/esp32c3-bt-lib/commit/b438f60a295183e7c67eb42ae05f4580f4b1ced0
 * Upstream date: 2023-06-12 21:42:40 +0800
 * Upstream subject: update libbtdm_app.a for ESP32C3 and ESP32S3(963cad48)
 * Source: libbtdm_app -> lld_scan.o -> r_lld_scan_frm_skip_isr_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_frm_skip_isr_hack(int param_1)

{
  bool bVar1;
  int iVar2;
  
  bVar1 = false;
  if ((_lld_scan_env != 0) && (iVar2 = *(int *)(_lld_scan_env + param_1 * 4), iVar2 != 0)) {
    bVar1 = *(char *)(iVar2 + 0x3d) == '\x01';
  }
  r_lld_scan_frm_skip_isr(param_1);
  if ((((bVar1) && (_lld_scan_env != 0)) &&
      (iVar2 = *(int *)(param_1 * 4 + _lld_scan_env), iVar2 != 0)) &&
     (*(char *)(_lld_scan_env + 0x17) != '\0')) {
    if (((iVar2 != 0) && (*(char *)(_lld_scan_env + 0x17) != '\0')) &&
       (*(char *)(iVar2 + 0x3d) == '\0')) {
                    /* WARNING: Could not recover jumptable at 0x00010024. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_ip_funcs_p + 0x3d8))(1);
      return;
    }
    return;
  }
  return;
}

