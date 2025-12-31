/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> llm.o -> r_llm_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llm_init(uint param_1)

{
  undefined1 uVar1;
  void *pvVar2;
  uint uVar3;
  void *pvVar4;
  int iVar5;
  undefined4 uVar6;
  undefined1 uStack_23;
  byte bStack_22;
  byte abStack_21 [9];
  
  if (param_1 != 1) {
    if (param_1 != 2) {
      if (param_1 == 0) {
        r_ke_task_create(&TASK_DESC_LLM_FLASH);
      }
      goto _L189;
    }
    uVar3 = 0;
    while( true ) {
      iVar5 = r_sdk_config_get_opts();
      if (*(byte *)(iVar5 + 0xd) <= uVar3) break;
      iVar5 = *(int *)(*(int *)((int)_p_llm_env + 8) + uVar3 * 0x44);
      if (iVar5 != 0) {
        r_ke_msg_free(iVar5 + -0xc);
      }
      uVar3 = uVar3 + 1 & 0xff;
    }
    r_ke_timer_clear(4,0);
    r_ke_timer_clear(6,0);
  }
  pvVar4 = *(void **)((int)_p_llm_env + 8);
  iVar5 = r_sdk_config_get_opts();
  memset(pvVar4,0,(uint)*(byte *)(iVar5 + 0xd) * 0x44);
  if ((*(int *)((int)_p_llm_env + 0xcc) != 0) && (*(char *)((int)_p_llm_env + 0xd7) == '\x02')) {
    iVar5 = r_sdk_config_get_opts_ext();
    if (*(char *)(iVar5 + 0x23) != '\0') {
      r_llm_env_adv_dup_filt_deinit_eco();
    }
  }
  uVar1 = *(undefined1 *)((int)_p_llm_env + 0xd0);
  uVar6 = *(undefined4 *)((int)_p_llm_env + 0xcc);
  memset(_p_llm_env,0,0xdc);
  pvVar2 = _p_llm_env;
  *(void **)((int)_p_llm_env + 8) = pvVar4;
  *(undefined1 *)((int)pvVar2 + 0xd0) = uVar1;
  *(undefined4 *)((int)pvVar2 + 0xcc) = uVar6;
  iVar5 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar5 + 0x23) != '\0') {
    llm_exception_list_init();
    llm_duplicate_list_init();
  }
  pvVar4 = _p_llm_env;
  *(undefined2 *)((int)_p_llm_env + 0xc4) = 900;
  *(undefined4 *)((int)pvVar4 + 0x9c) = 0x148001b;
  *(undefined2 *)((int)pvVar4 + 0xa2) = 0x707;
  memcpy(pvVar4,&le_default_evt_mask,8);
  pvVar4 = _p_llm_env;
  memset((void *)((int)_p_llm_env + 0x18),0xff,4);
  *(undefined1 *)((int)pvVar4 + 0x1c) = 0x1f;
  memset((void *)((int)pvVar4 + 0x1d),0xff,4);
  *(undefined1 *)((int)pvVar4 + 0x21) = 0x1f;
  uStack_23 = 6;
  iVar5 = (*_rwip_param)(1,&uStack_23,(int)pvVar4 + 0xc,_rwip_param);
  if (iVar5 != 0) {
    memcpy((void *)((int)_p_llm_env + 0xc),&co_default_bdaddr,6);
  }
  uStack_23 = 0x20;
  (*_rwip_param)(0x80,&uStack_23,(int)_p_llm_env + 0xa4,_rwip_param);
  uStack_23 = 1;
  iVar5 = (*_rwip_param)(0x15,&uStack_23,&bStack_22,_rwip_param);
  if (iVar5 == 0) {
    *(byte *)((int)_p_llm_env + 0xd8) = bStack_22 & 1;
  }
  else {
    *(undefined1 *)((int)_p_llm_env + 0xd8) = 1;
  }
  uStack_23 = 1;
  iVar5 = (*_rwip_param)(0x19,&uStack_23,abStack_21,_rwip_param);
  if (iVar5 == 0) {
    *(byte *)((int)_p_llm_env + 0xd9) = abStack_21[0] & 1;
  }
  else {
    *(undefined1 *)((int)_p_llm_env + 0xd9) = 1;
  }
  iVar5 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar5 + 0x19) == '\x02') {
    *(undefined1 *)((int)_p_llm_env + 0xd9) = 0;
  }
  iVar5 = r_sdk_config_get_opts_ext();
  pvVar4 = _p_llm_env;
  if (*(char *)(iVar5 + 0x1b) == '\0') {
    *(undefined1 *)((int)_p_llm_env + 0xd9) = 0;
    *(undefined1 *)((int)pvVar4 + 0x22) = 1;
  }
  uStack_23 = 1;
  iVar5 = (*_rwip_param)(0x16,&uStack_23,(int)_p_llm_env + 0xd5,_rwip_param);
  if (iVar5 != 0) {
    *(undefined1 *)((int)_p_llm_env + 0xd5) = 1;
  }
_L189:
  r_ble_log_internal_x1(0x400e0144,(uint)*(byte *)((int)_p_llm_env + 0xd9) << 8 | param_1);
  return;
}

