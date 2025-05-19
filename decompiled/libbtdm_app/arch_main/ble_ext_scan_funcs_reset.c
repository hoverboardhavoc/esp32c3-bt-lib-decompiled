/*
 * Last changed at upstream commit 72599d583c232ea78d6461b5b502426c6e5a1ec9
 * https://github.com/espressif/esp32c3-bt-lib/commit/72599d583c232ea78d6461b5b502426c6e5a1ec9
 * Upstream date: 2025-05-19 16:27:45 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(6cfabcd8)
 * Source: libbtdm_app -> arch_main.o -> ble_ext_scan_funcs_reset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ble_ext_scan_funcs_reset(void)

{
  int iVar1;
  
  iVar1 = _r_ip_funcs_p;
  *(undefined **)(_r_ip_funcs_p + 0x170) = &r_lld_sync_start_eco;
  *(undefined **)(iVar1 + 0x8b0) = &r_lld_sync_start_eco;
  *(undefined **)(iVar1 + 0x7a4) = &r_lld_sync_insert_eco;
  *(undefined **)(iVar1 + 0x8b4) = &r_lld_sync_insert_eco;
  *(undefined **)(iVar1 + 0x3f4) = &r_lld_scan_frm_eof_isr_eco;
  *(undefined **)(iVar1 + 0x8ac) = &r_lld_scan_frm_eof_isr_eco;
  return;
}

