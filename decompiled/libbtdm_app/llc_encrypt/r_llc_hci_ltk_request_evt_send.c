/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc_encrypt.o -> r_llc_hci_ltk_request_evt_send
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_hci_ltk_request_evt_send(undefined4 param_1,undefined2 param_2,void *param_3)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)
           (**(code **)(_r_modules_funcs_p + 200))
                     (0x1104,param_1,0,0xe,*(code **)(_r_modules_funcs_p + 200));
  *puVar1 = 5;
  *(short *)(puVar1 + 2) = (short)param_1;
  *(undefined2 *)(puVar1 + 0xc) = param_2;
  memcpy(puVar1 + 4,param_3,8);
                    /* WARNING: Could not recover jumptable at 0x00010be2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x8c))(puVar1);
  return;
}

