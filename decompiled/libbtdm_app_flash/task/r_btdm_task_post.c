/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> task.o -> r_btdm_task_post
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_btdm_task_post(uint param_1,void *param_2,size_t param_3,int param_4)

{
  void *pvVar1;
  undefined4 uVar2;
  int iVar3;
  uint uStack_28;
  void *pvStack_24;
  
  if (0xd < param_1) {
    return 0xffffffff;
  }
  if ((0x2f84U >> (param_1 & 0x1f) & 1) != 0) {
    pvStack_24 = (void *)0x0;
    uStack_28 = param_1 & 0xff;
    pvVar1 = param_2;
    if ((param_2 != (void *)0x0) && (pvVar1 = param_2, 0 < (int)param_3)) {
      uStack_28 = uStack_28 | 0x80000000;
      uVar2 = 0xfffffffe;
      pvStack_24 = (void *)(**(code **)(_r_osi_funcs_p + 0x74))
                                     (param_3,*(code **)(_r_osi_funcs_p + 0x74));
      if (pvStack_24 == (void *)0x0) goto _L3;
      memcpy(pvStack_24,param_2,param_3);
      pvVar1 = pvStack_24;
    }
    pvStack_24 = pvVar1;
    iVar3 = (**(code **)(_r_osi_funcs_p + 0x54))
                      (_g_rw_schd_queue,&uStack_28,-param_4,*(code **)(_r_osi_funcs_p + 0x54));
    if ((param_4 != 0) && (iVar3 != 1)) {
      if (0 < _g_bt_plf_log_level) {
        ets_printf("Send Queue Failed\n");
      }
      uVar2 = 0xfffffffd;
      (**(code **)(_r_osi_funcs_p + 0x7c))(pvStack_24,*(code **)(_r_osi_funcs_p + 0x7c));
      goto _L3;
    }
  }
  uVar2 = 0;
_L3:
  (**(code **)(_r_osi_funcs_p + 0x38))(btdm_ol_task_env._8_4_,*(code **)(_r_osi_funcs_p + 0x38));
  return uVar2;
}

