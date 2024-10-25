/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> vhci.o -> r_vhci_notify_host_send_available
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_vhci_notify_host_send_available(void)

{
  int *piVar1;
  code *pcVar2;
  
  if (*_vhci_env_p != '\0') {
    piVar1 = (int *)(_vhci_env_p + 8);
    *_vhci_env_p = '\0';
    if (((undefined4 *)*piVar1 != (undefined4 *)0x0) &&
       (pcVar2 = *(code **)*piVar1, pcVar2 != (code *)0x0)) {
      (*pcVar2)();
    }
                    /* WARNING: Could not recover jumptable at 0x0001024e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_osi_funcs_p + 0x38))(*(undefined4 *)(_vhci_env_p + 4));
    return;
  }
  return;
}

