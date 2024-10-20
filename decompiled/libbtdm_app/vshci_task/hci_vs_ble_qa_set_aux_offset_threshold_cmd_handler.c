/*
 * Last changed at upstream commit eeb2782618e0ab8cf0cf609c98c6a0c86d691a6c
 * https://github.com/espressif/esp32c3-bt-lib/commit/eeb2782618e0ab8cf0cf609c98c6a0c86d691a6c
 * Upstream date: 2024-10-20 16:32:16 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(52ee788)
 * Source: libbtdm_app -> vshci_task.o -> hci_vs_ble_qa_set_aux_offset_threshold_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
hci_vs_ble_qa_set_aux_offset_threshold_cmd_handler
          (undefined1 param_1,undefined4 *param_2,undefined4 param_3)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)
           (**(code **)(_r_modules_funcs_p + 200))
                     (0x1101,param_3,0xfd13,2,*(code **)(_r_modules_funcs_p + 200));
  uVar1 = lld_aux_ptr_thr_set(*param_2,param_2[1]);
  *puVar2 = uVar1;
  puVar2[1] = param_1;
  (**(code **)(_r_ip_funcs_p + 0x8c))(puVar2,*(code **)(_r_ip_funcs_p + 0x8c));
  return 0;
}

