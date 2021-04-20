/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtdm_app -> llm.o -> r_llm_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llm_init(int param_1)

{
  undefined1 uVar1;
  void *pvVar2;
  uint uVar3;
  void *__s;
  int iVar4;
  undefined4 uVar5;
  undefined1 uStack_23;
  byte bStack_22;
  byte abStack_21 [9];
  
  if (param_1 != 1) {
    if (param_1 == 0) {
      (**(code **)(_r_modules_funcs_p + 0x164))
                (0,&TASK_DESC_LLM_HACK,*(code **)(_r_modules_funcs_p + 0x164));
      return;
    }
    if (param_1 != 2) {
      return;
    }
    for (uVar3 = 0; iVar4 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38)),
        uVar3 < *(byte *)(iVar4 + 0xd); uVar3 = uVar3 + 1 & 0xff) {
      iVar4 = *(int *)(*(int *)((int)_p_llm_env + 8) + uVar3 * 0x44);
      if (iVar4 != 0) {
        (**(code **)(_r_modules_funcs_p + 0xd8))(iVar4 + -0xc,*(code **)(_r_modules_funcs_p + 0xd8))
        ;
      }
    }
    (**(code **)(_r_modules_funcs_p + 0xb8))(4,0,*(code **)(_r_modules_funcs_p + 0xb8));
    (**(code **)(_r_modules_funcs_p + 0xb8))(6,0,*(code **)(_r_modules_funcs_p + 0xb8));
  }
  __s = *(void **)((int)_p_llm_env + 8);
  iVar4 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  memset(__s,0,(uint)*(byte *)(iVar4 + 0xd) * 0x44);
  uVar5 = *(undefined4 *)((int)_p_llm_env + 0xcc);
  uVar1 = *(undefined1 *)((int)_p_llm_env + 0xd0);
  memset(_p_llm_env,0,0xdc);
  pvVar2 = _p_llm_env;
  *(void **)((int)_p_llm_env + 8) = __s;
  *(undefined4 *)((int)pvVar2 + 0xcc) = uVar5;
  *(undefined1 *)((int)pvVar2 + 0xd0) = uVar1;
  llm_exception_list_init();
  llm_duplicate_list_init();
  pvVar2 = _p_llm_env;
  *(undefined2 *)((int)_p_llm_env + 0xc4) = 900;
  *(undefined4 *)((int)pvVar2 + 0x9c) = 0x148001b;
  *(undefined2 *)((int)pvVar2 + 0xa2) = 0x707;
  memcpy(pvVar2,&_LANCHOR1,8);
  pvVar2 = _p_llm_env;
  memset((void *)((int)_p_llm_env + 0x18),0xff,5);
  *(undefined1 *)((int)pvVar2 + 0x1c) = 0x1f;
  memset((void *)((int)pvVar2 + 0x1d),0xff,5);
  *(undefined1 *)((int)pvVar2 + 0x21) = 0x1f;
  uStack_23 = 6;
  iVar4 = (*_rwip_param)(1,&uStack_23,(int)pvVar2 + 0xc,_rwip_param);
  if (iVar4 != 0) {
    memcpy((void *)((int)_p_llm_env + 0xc),&co_default_bdaddr,6);
  }
  uStack_23 = 0x20;
  (*_rwip_param)(0x80,&uStack_23,(int)_p_llm_env + 0xa4,_rwip_param);
  uStack_23 = 1;
  iVar4 = (*_rwip_param)(0x15,&uStack_23,&bStack_22,_rwip_param);
  if (iVar4 == 0) {
    *(byte *)((int)_p_llm_env + 0xd8) = bStack_22 & 1;
  }
  else {
    *(undefined1 *)((int)_p_llm_env + 0xd8) = 1;
  }
  uStack_23 = 1;
  iVar4 = (*_rwip_param)(0x19,&uStack_23,abStack_21,_rwip_param);
  if (iVar4 == 0) {
    *(byte *)((int)_p_llm_env + 0xd9) = abStack_21[0] & 1;
  }
  else {
    *(undefined1 *)((int)_p_llm_env + 0xd9) = 1;
  }
  uStack_23 = 1;
  iVar4 = (*_rwip_param)(0x16,&uStack_23,(int)_p_llm_env + 0xd5,_rwip_param);
  if (iVar4 != 0) {
    *(undefined1 *)((int)_p_llm_env + 0xd5) = 1;
  }
  return;
}

