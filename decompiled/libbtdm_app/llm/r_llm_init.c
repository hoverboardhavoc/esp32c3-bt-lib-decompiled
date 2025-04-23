/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  void *pvVar4;
  int iVar5;
  byte bVar6;
  undefined4 uVar7;
  undefined1 uStack_23;
  byte bStack_22;
  byte abStack_21 [9];
  
  if (param_1 != 1) {
    if (param_1 != 2) {
      if (param_1 != 0) {
        return;
      }
                    /* WARNING: Could not recover jumptable at 0x0001067e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_modules_funcs_p + 0x164))
                (&TASK_DESC_LLM,*(code **)(_r_modules_funcs_p + 0x164));
      return;
    }
    for (uVar3 = 0; iVar5 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38)),
        uVar3 < *(byte *)(iVar5 + 0xd); uVar3 = uVar3 + 1 & 0xff) {
      iVar5 = *(int *)(*(int *)((int)_p_llm_env + 8) + uVar3 * 0x44);
      if (iVar5 != 0) {
        (**(code **)(_r_modules_funcs_p + 0xd8))(iVar5 + -0xc,*(code **)(_r_modules_funcs_p + 0xd8))
        ;
      }
    }
    (**(code **)(_r_modules_funcs_p + 0xb8))(4,0,*(code **)(_r_modules_funcs_p + 0xb8));
    (**(code **)(_r_modules_funcs_p + 0xb8))(6,0,*(code **)(_r_modules_funcs_p + 0xb8));
  }
  pvVar4 = *(void **)((int)_p_llm_env + 8);
  iVar5 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  memset(pvVar4,0,(uint)*(byte *)(iVar5 + 0xd) * 0x44);
  if (((*(int *)((int)_p_llm_env + 0xcc) != 0) && (*(char *)((int)_p_llm_env + 0xd7) == '\x02')) &&
     (iVar5 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0)),
     *(char *)(iVar5 + 0x23) != '\0')) {
    (**(code **)(_r_ip_funcs_p + 0x53c))(*(code **)(_r_ip_funcs_p + 0x53c));
  }
  uVar1 = *(undefined1 *)((int)_p_llm_env + 0xd0);
  uVar7 = *(undefined4 *)((int)_p_llm_env + 0xcc);
  memset(_p_llm_env,0,0xdc);
  pvVar2 = _p_llm_env;
  *(void **)((int)_p_llm_env + 8) = pvVar4;
  *(undefined1 *)((int)pvVar2 + 0xd0) = uVar1;
  *(undefined4 *)((int)pvVar2 + 0xcc) = uVar7;
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
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
  pvVar4 = _p_llm_env;
  if (iVar5 != 0) {
    memcpy((void *)((int)_p_llm_env + 0xc),&co_default_bdaddr,6);
  }
  uStack_23 = 0x20;
  (*_rwip_param)(0x80,&uStack_23,(int)pvVar4 + 0xa4,_rwip_param);
  bVar6 = 1;
  uStack_23 = 1;
  iVar5 = (*_rwip_param)(0x15,&uStack_23,&bStack_22,_rwip_param);
  if (iVar5 == 0) {
    bVar6 = bStack_22 & 1;
  }
  *(byte *)((int)_p_llm_env + 0xd8) = bVar6;
  bVar6 = 1;
  uStack_23 = 1;
  iVar5 = (*_rwip_param)(0x19,&uStack_23,abStack_21,_rwip_param);
  if (iVar5 == 0) {
    bVar6 = abStack_21[0] & 1;
  }
  *(byte *)((int)_p_llm_env + 0xd9) = bVar6;
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar5 + 0x19) == '\x02') {
    *(undefined1 *)((int)_p_llm_env + 0xd9) = 0;
  }
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  pvVar4 = _p_llm_env;
  if (*(char *)(iVar5 + 0x1b) == '\0') {
    *(undefined1 *)((int)_p_llm_env + 0xd9) = 0;
    *(undefined1 *)((int)pvVar4 + 0x22) = 1;
  }
  uStack_23 = 1;
  iVar5 = (*_rwip_param)(0x16,&uStack_23,(int)pvVar4 + 0xd5,_rwip_param);
  if (iVar5 != 0) {
    *(undefined1 *)((int)_p_llm_env + 0xd5) = 1;
  }
  return;
}

