/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app -> llm_scan.o -> lld_per_adv_rx_end_ind_handler_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 lld_per_adv_rx_end_ind_handler_hack(byte *param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  ushort *puVar5;
  undefined1 *puVar6;
  undefined2 *puVar7;
  int iVar8;
  undefined1 uVar9;
  int iVar10;
  ushort uVar11;
  
  iVar8 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar8 + 0x18) == '\0') {
    return 0;
  }
  bVar1 = *param_1;
  iVar8 = (uint)bVar1 * 0x44;
  iVar3 = *(int *)(_p_llm_env + 8) + iVar8;
  uVar9 = *(undefined1 *)(iVar3 + 0x41);
  uVar11 = (ushort)bVar1;
  if (*(char *)(iVar3 + 0x40) != '\x0e') {
    if ((byte)(*(char *)(iVar3 + 0x40) - 0xfU) < 2) {
      (**(code **)(_r_ip_funcs_p + 0x6f4))(iVar3 + 0xc,*(code **)(_r_ip_funcs_p + 0x6f4));
      uVar4 = (**(code **)(_r_ip_funcs_p + 0x4c8))
                        (iVar3 + 4,uVar9,*(code **)(_r_ip_funcs_p + 0x4c8));
      if (((uVar4 < 0xc) && (iVar10 = uVar4 * 10 + _p_llm_env, (*(byte *)(iVar10 + 0x2d) & 4) != 0))
         && (((int)(uint)*(ushort *)(iVar10 + 0x2a) >>
              (*(byte *)(*(int *)(_p_llm_env + 8) + iVar8 + 0x28) & 0x1f) & 1U) != 0)) {
        (**(code **)(_r_ip_funcs_p + 600))(iVar3 + 4,uVar9,*(code **)(_r_ip_funcs_p + 600));
      }
      cVar2 = *(char *)(*(int *)(_p_llm_env + 8) + iVar8 + 0x40);
      if (cVar2 == '\x10') {
        (**(code **)(_r_ip_funcs_p + 0x4b8))(0x2046,0,*(code **)(_r_ip_funcs_p + 0x4b8));
      }
      else if (cVar2 == '\x0f') {
        puVar6 = (undefined1 *)
                 (**(code **)(_r_modules_funcs_p + 200))
                           (0x1104,0,0x3e,4,*(code **)(_r_modules_funcs_p + 200));
        *puVar6 = 0x10;
        iVar3 = _r_ip_funcs_p;
        *(ushort *)(puVar6 + 2) = uVar11;
        (**(code **)(iVar3 + 0x8c))(*(code **)(iVar3 + 0x8c));
      }
      if (*(short *)(*(int *)(_p_llm_env + 8) + iVar8 + 0x2a) != 0xff) {
        puVar5 = (ushort *)
                 (**(code **)(_r_modules_funcs_p + 200))(1,0,8,*(code **)(_r_modules_funcs_p + 200))
        ;
        iVar3 = _p_llm_env;
        *puVar5 = uVar11;
        uVar9 = 0x16;
        iVar3 = *(int *)(iVar3 + 8) + iVar8;
        if (*(char *)(iVar3 + 0x40) != '\x10') {
          uVar9 = 8;
        }
        *(undefined1 *)(puVar5 + 1) = uVar9;
        uVar9 = *(undefined1 *)(iVar3 + 0x29);
        *(undefined1 *)(puVar5 + 3) = 0;
        puVar5[2] = 0;
        *(undefined1 *)((int)puVar5 + 3) = uVar9;
        (**(code **)(_r_modules_funcs_p + 0xe0))(*(code **)(_r_modules_funcs_p + 0xe0));
      }
    }
    else {
      (**(code **)(_r_plf_funcs_p + 8))(0,"llm_scan.c",0xbcf,*(code **)(_r_plf_funcs_p + 8));
    }
    goto _L845;
  }
  if (param_1[1] == 0) {
    (**(code **)(_r_ip_funcs_p + 0x4b8))(0x2045,0,param_2,param_3,*(code **)(_r_ip_funcs_p + 0x4b8))
    ;
    puVar7 = (undefined2 *)
             (**(code **)(_r_modules_funcs_p + 200))
                       (0x1104,0,0x3e,0x12,*(code **)(_r_modules_funcs_p + 200));
    *puVar7 = 0x440e;
    iVar3 = _p_llm_env;
    puVar7[1] = uVar11;
    iVar3 = *(int *)(iVar3 + 8) + iVar8;
    *(undefined1 *)(puVar7 + 2) = *(undefined1 *)(iVar3 + 0x28);
    *(undefined1 *)((int)puVar7 + 5) = *(undefined1 *)(iVar3 + 0x41);
    memcpy(puVar7 + 3,(void *)(iVar3 + 4),6);
    *(undefined1 *)(puVar7 + 6) = 1;
    puVar7[7] = 6;
    *(undefined1 *)(puVar7 + 8) = 0;
    iVar3 = _r_ip_funcs_p;
_L858:
    (**(code **)(iVar3 + 0x8c))(puVar7,*(code **)(iVar3 + 0x8c));
  }
  else {
    if (param_1[1] == 8) {
      puVar7 = (undefined2 *)
               (**(code **)(_r_modules_funcs_p + 200))
                         (0x1104,0,0x3e,0x12,*(code **)(_r_modules_funcs_p + 200));
      *puVar7 = 0x3e0e;
      iVar3 = _p_llm_env;
      puVar7[1] = uVar11;
      iVar3 = *(int *)(iVar3 + 8) + iVar8;
      *(undefined1 *)(puVar7 + 2) = *(undefined1 *)(iVar3 + 0x28);
      *(undefined1 *)((int)puVar7 + 5) = *(undefined1 *)(iVar3 + 0x41);
      memcpy(puVar7 + 3,(void *)(iVar3 + 4),6);
      *(undefined1 *)(puVar7 + 6) = 1;
      puVar7[7] = 6;
      iVar3 = _r_ip_funcs_p;
      *(undefined1 *)(puVar7 + 8) = 0;
      goto _L858;
    }
    (**(code **)(_r_plf_funcs_p + 0xc))
              ((uint)bVar1,"llm_scan.c",0xbc4,*(code **)(_r_plf_funcs_p + 0xc));
  }
  (**(code **)(_r_modules_funcs_p + 0xd8))
            (*(int *)(*(int *)(_p_llm_env + 8) + iVar8) + -0xc,*(code **)(_r_modules_funcs_p + 0xd8)
            );
  *(undefined4 *)(*(int *)(_p_llm_env + 8) + iVar8) = 0;
_L845:
  *(undefined1 *)(*(int *)(_p_llm_env + 8) + iVar8 + 0x40) = 0;
  return 0;
}

