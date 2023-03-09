/*
 * Last changed at upstream commit 5c6ab5248a124cffc731a9e4764473fdeef38054
 * https://github.com/espressif/esp32c3-bt-lib/commit/5c6ab5248a124cffc731a9e4764473fdeef38054
 * Upstream date: 2023-03-09 14:58:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(85a1090)
 * Source: libbtdm_app -> task.o -> r_btdm_task_post_impl
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
r_btdm_task_post_impl(uint param_1,undefined1 param_2,void *param_3,size_t param_4,int param_5)

{
  void *pvVar1;
  undefined4 uVar2;
  code *pcVar3;
  int iVar4;
  undefined4 uStack_28;
  void *pvStack_24;
  
  if ((0x2f84U >> (param_1 & 0x1f) & 1) != 0) {
    pvStack_24 = (void *)0x0;
    uStack_28 = (uint)CONCAT11(param_2,(char)param_1);
    pvVar1 = param_3;
    if ((param_3 != (void *)0x0) && (pvVar1 = param_3, 0 < (int)param_4)) {
      uStack_28 = uStack_28 | 0x80000000;
      uVar2 = 0xfffffffe;
      pvStack_24 = (void *)(**(code **)(_r_osi_funcs_p + 0x74))
                                     (param_4,*(code **)(_r_osi_funcs_p + 0x74));
      if (pvStack_24 == (void *)0x0) goto _L3;
      memcpy(pvStack_24,param_3,param_4);
      pvVar1 = pvStack_24;
    }
    pvStack_24 = pvVar1;
    iVar4 = (**(code **)(_r_osi_funcs_p + 0x54))
                      (_g_rw_schd_queue,&uStack_28,-param_5,*(code **)(_r_osi_funcs_p + 0x54));
    if ((param_5 != 0) && (iVar4 != 1)) {
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
  pcVar3 = *(code **)(_r_osi_funcs_p + 0x38);
  iVar4 = (**(code **)(_r_plf_funcs_p + 0xf8))(*(code **)(_r_plf_funcs_p + 0xf8));
  (*pcVar3)(*(undefined4 *)(iVar4 + 4));
  return uVar2;
}

