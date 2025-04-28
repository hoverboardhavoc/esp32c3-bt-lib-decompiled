/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc_hci.o -> r_llc_hci_nb_cmp_pkts_evt_send
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_hci_nb_cmp_pkts_evt_send(undefined4 param_1,undefined2 param_2)

{
  int iVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)
           (**(code **)(_r_modules_funcs_p + 200))
                     (0x1103,param_1,0x13,6,*(code **)(_r_modules_funcs_p + 200));
  *puVar2 = 1;
  iVar1 = _r_ip_funcs_p;
  *(short *)(puVar2 + 2) = (short)param_1;
  *(undefined2 *)(puVar2 + 4) = param_2;
                    /* WARNING: Could not recover jumptable at 0x00010540. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(iVar1 + 0x8c))(*(code **)(iVar1 + 0x8c));
  return;
}

