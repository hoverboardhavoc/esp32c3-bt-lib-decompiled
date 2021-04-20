/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtdm_app -> task.o -> btdm_vnd_offload_post
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x00010040) */
/* WARNING: Removing unreachable block (ram,0x00010058) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 btdm_vnd_offload_post(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 uStack_28;
  undefined1 uStack_27;
  undefined2 uStack_26;
  undefined4 uStack_24;
  
  if (param_1 == 0) {
    uStack_26 = 0;
    uStack_28 = 0xd;
    uStack_27 = 0;
    uStack_24 = param_2;
    iVar2 = (**(code **)(_r_osi_funcs_p + 0x54))
                      (_g_rw_schd_queue,&uStack_28,0xffffffff,*(code **)(_r_osi_funcs_p + 0x54));
    if (iVar2 == 1) {
      uVar1 = 0;
    }
    else {
      if (0 < _g_bt_plf_log_level) {
        ets_printf("Send Queue Failed\n");
      }
      uVar1 = 0xfffffffd;
      (**(code **)(_r_osi_funcs_p + 0x7c))(uStack_24,*(code **)(_r_osi_funcs_p + 0x7c));
    }
    (**(code **)(_r_osi_funcs_p + 0x38))(g_rw_schd_sem,*(code **)(_r_osi_funcs_p + 0x38));
    return uVar1;
  }
  return 0xffffffff;
}

