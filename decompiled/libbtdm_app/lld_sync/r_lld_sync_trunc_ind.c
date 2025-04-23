/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_sync.o -> r_lld_sync_trunc_ind
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_sync_trunc_ind(int param_1)

{
  int iVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)
           (**(code **)(_r_modules_funcs_p + 200))
                     (0x204,0,0xff,0x1c,*(code **)(_r_modules_funcs_p + 200));
  (**(code **)(_r_ip_funcs_p + 0x168))
            (*(undefined4 *)(&lld_sync_env + param_1 * 4),2,*(code **)(_r_ip_funcs_p + 0x168));
  *puVar2 = (char)param_1;
  puVar2[0xb] = 0x7f;
  *(undefined2 *)(puVar2 + 0xc) = 0x27f;
  iVar1 = _r_modules_funcs_p;
  puVar2[0xe] = 0;
                    /* WARNING: Could not recover jumptable at 0x00010384. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(iVar1 + 0xe0))(puVar2,*(code **)(iVar1 + 0xe0));
  return;
}

