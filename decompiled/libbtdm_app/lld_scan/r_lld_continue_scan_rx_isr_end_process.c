/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app -> lld_scan.o -> r_lld_continue_scan_rx_isr_end_process
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
      iVar2 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
      if (*(char *)(iVar2 + 0x18) == '\0') {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x53d,*(code **)(_r_plf_funcs_p + 8));
      }
      (**(code **)(_r_ip_funcs_p + 0x448))(param_1,*(code **)(_r_ip_funcs_p + 0x448));
    }
    *(undefined1 *)(iVar1 + 0x3e) = 0;
  }
  else if (*(char *)(iVar1 + 0x3d) != '\x02') {
    return;
  }
  *(undefined1 *)(iVar1 + 0x3d) = 0;
  return;
}

