/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app -> llm_adv.o -> lld_scan_req_ind_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 lld_scan_req_ind_handler(byte *param_1)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  
  puVar2 = (undefined4 *)(*(int *)(_p_llm_env + 8) + (uint)*param_1 * 0x44);
  puVar3 = (undefined1 *)*puVar2;
  if (1 < (byte)(*(char *)(puVar2 + 0x10) - 2U)) {
    (**(code **)(_r_plf_funcs_p + 0xc))("llm_adv.c",0xd46,*(code **)(_r_plf_funcs_p + 0xc));
  }
  if (puVar3[0x19] != '\0') {
    puVar1 = (undefined1 *)
             (**(code **)(_r_modules_funcs_p + 200))
                       (0x1104,0,0x3e,9,*(code **)(_r_modules_funcs_p + 200));
    *puVar1 = 0x13;
    puVar1[1] = *puVar3;
    puVar1[2] = param_1[1];
    memcpy(puVar1 + 3,param_1 + 2,6);
    (**(code **)(_r_ip_funcs_p + 0x8c))(puVar1,*(code **)(_r_ip_funcs_p + 0x8c));
  }
  return 0;
}

