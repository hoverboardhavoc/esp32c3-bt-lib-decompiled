/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> vhci.o -> r_vhci_notify_host_send_available
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_vhci_notify_host_send_available(void)

{
  char *pcVar1;
  code *pcVar2;
  
  pcVar1 = _vhci_env_p;
  if (*_vhci_env_p != '\0') {
    *_vhci_env_p = '\0';
    if ((*(undefined4 **)(pcVar1 + 8) != (undefined4 *)0x0) &&
       (pcVar2 = (code *)**(undefined4 **)(pcVar1 + 8), pcVar2 != (code *)0x0)) {
      (*pcVar2)();
    }
                    /* WARNING: Could not recover jumptable at 0x00010314. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_osi_funcs_p + 0x38))
              (*(undefined4 *)(_vhci_env_p + 4),*(code **)(_r_osi_funcs_p + 0x38));
    return;
  }
  return;
}

