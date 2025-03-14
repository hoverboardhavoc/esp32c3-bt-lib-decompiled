/*
 * Last changed at upstream commit e668c2d101ee46ee1950819607694fb852aecae0
 * https://github.com/espressif/esp32c3-bt-lib/commit/e668c2d101ee46ee1950819607694fb852aecae0
 * Upstream date: 2025-03-14 11:07:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(6e312587)
 * Source: libbtdm_app_flash -> lld_scan.o -> r_lld_continue_scan_rx_isr_end_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_continue_scan_rx_isr_end_process(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(_lld_scan_env + param_1 * 4);
  if ((*(char *)(iVar1 + 0x3e) == '\x02') ||
     ((*(char *)(iVar1 + 0x43) == '\0' && (*(char *)(iVar1 + 0x3e) == '\x01')))) {
    if (*(char *)(iVar1 + 0x3d) == '\x03') {
      iVar2 = r_sdk_config_get_opts_ext();
      if (*(char *)(iVar2 + 0x18) == '\0') {
        r_assert_err(0,"lld_scan.c",0x4f7);
      }
      r_lld_scan_trunc_ind(param_1);
    }
    *(undefined1 *)(iVar1 + 0x3e) = 0;
  }
  else if (*(char *)(iVar1 + 0x3d) != '\x02') {
    return;
  }
  *(undefined1 *)(iVar1 + 0x3d) = 0;
  return;
}

