/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc_con_upd.o -> r_llc_hci_con_param_req_evt_send
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_hci_con_param_req_evt_send
               (undefined4 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,
               undefined2 param_5)

{
  int iVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)
           (**(code **)(_r_modules_funcs_p + 200))
                     (0x1104,param_1,0x3e,0xc,*(code **)(_r_modules_funcs_p + 200));
  *puVar2 = 6;
  iVar1 = _r_ip_funcs_p;
  *(short *)(puVar2 + 2) = (short)param_1;
  *(undefined2 *)(puVar2 + 4) = param_2;
  *(undefined2 *)(puVar2 + 6) = param_3;
  *(undefined2 *)(puVar2 + 8) = param_4;
  *(undefined2 *)(puVar2 + 10) = param_5;
                    /* WARNING: Could not recover jumptable at 0x00010d4a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(iVar1 + 0x8c))(*(code **)(iVar1 + 0x8c));
  return;
}

