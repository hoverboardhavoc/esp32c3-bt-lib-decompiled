/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> hci_tl.o -> r_hci_tl_send
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_hci_tl_send(int param_1)

{
  int iVar1;
  code *pcVar2;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  if (*(short *)(param_1 + 4) == 0x1106) {
    pcVar2 = *(code **)(_r_modules_funcs_p + 0x44);
  }
  else {
    iVar1 = (**(code **)(_r_ip_funcs_p + 8))(param_1,*(code **)(_r_ip_funcs_p + 8));
    if (iVar1 != 0) goto _L147;
    pcVar2 = *(code **)(_r_modules_funcs_p + 0x44);
  }
  (*pcVar2)(&hci_tl_env,param_1,pcVar2);
_L147:
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
                    /* WARNING: Could not recover jumptable at 0x00010ad6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x6c))();
  return;
}

