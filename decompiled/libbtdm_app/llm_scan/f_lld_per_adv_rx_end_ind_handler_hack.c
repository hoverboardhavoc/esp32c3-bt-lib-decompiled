/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app -> llm_scan.o -> f_lld_per_adv_rx_end_ind_handler_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_lld_per_adv_rx_end_ind_handler_hack(byte *param_1)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  ushort *puVar6;
  undefined1 *puVar7;
  undefined2 *puVar8;
  undefined1 uVar9;
  int iVar10;
  ushort uVar11;
  
  bVar1 = *param_1;
  iVar3 = (uint)bVar1 * 0x44;
  iVar4 = *(int *)(_p_llm_env + 8) + iVar3;
  uVar9 = *(undefined1 *)(iVar4 + 0x41);
  uVar11 = (ushort)bVar1;
  if (*(char *)(iVar4 + 0x40) != '\x0e') {
    if ((byte)(*(char *)(iVar4 + 0x40) - 0xfU) < 2) {
      (**(code **)(_r_ip_funcs_p + 0x6f4))(iVar4 + 0xc,*(code **)(_r_ip_funcs_p + 0x6f4));
      uVar5 = (**(code **)(_r_ip_funcs_p + 0x4c8))
                        (iVar4 + 4,uVar9,*(code **)(_r_ip_funcs_p + 0x4c8));
      if (uVar5 < 0xc) {
        iVar10 = uVar5 * 10 + _p_llm_env;
        if ((*(byte *)(iVar10 + 0x2d) & 4) != 0) {
          if (((int)(uint)*(ushort *)(iVar10 + 0x2a) >>
               (*(byte *)(*(int *)(_p_llm_env + 8) + iVar3 + 0x28) & 0x1f) & 1U) != 0) {
            (**(code **)(_r_ip_funcs_p + 600))(iVar4 + 4,uVar9,*(code **)(_r_ip_funcs_p + 600));
          }
        }
      }
      cVar2 = *(char *)(*(int *)(_p_llm_env + 8) + iVar3 + 0x40);
      if (cVar2 == '\x10') {
        (**(code **)(_r_ip_funcs_p + 0x4b8))(0x2046,0,*(code **)(_r_ip_funcs_p + 0x4b8));
      }
      else if (cVar2 == '\x0f') {
        puVar7 = (undefined1 *)
                 (**(code **)(_r_modules_funcs_p + 200))
                           (0x1104,0,0x3e,4,*(code **)(_r_modules_funcs_p + 200));
        *puVar7 = 0x10;
        iVar4 = _r_ip_funcs_p;
        *(ushort *)(puVar7 + 2) = uVar11;
        (**(code **)(iVar4 + 0x8c))(*(code **)(iVar4 + 0x8c));
      }
      if (*(short *)(*(int *)(_p_llm_env + 8) + iVar3 + 0x2a) != 0xff) {
        puVar6 = (ushort *)
                 (**(code **)(_r_modules_funcs_p + 200))(1,0,8,*(code **)(_r_modules_funcs_p + 200))
        ;
        iVar4 = _p_llm_env;
        *puVar6 = uVar11;
        uVar9 = 0x16;
        iVar4 = *(int *)(iVar4 + 8) + iVar3;
        if (*(char *)(iVar4 + 0x40) != '\x10') {
          uVar9 = 8;
        }
        *(undefined1 *)(puVar6 + 1) = uVar9;
        uVar9 = *(undefined1 *)(iVar4 + 0x29);
        *(undefined1 *)(puVar6 + 3) = 0;
        puVar6[2] = 0;
        *(undefined1 *)((int)puVar6 + 3) = uVar9;
        (**(code **)(_r_modules_funcs_p + 0xe0))(*(code **)(_r_modules_funcs_p + 0xe0));
      }
    }
    else {
      (**(code **)(_r_plf_funcs_p + 8))(0,"llm_scan.c",0xbef,*(code **)(_r_plf_funcs_p + 8));
    }
    goto _L849;
  }
  if (param_1[1] == 0) {
    llm_sync_cancel_cc_act_id = 0xff;
    (**(code **)(_r_ip_funcs_p + 0x4b8))(0x2045,0,*(code **)(_r_ip_funcs_p + 0x4b8));
    puVar8 = (undefined2 *)
             (**(code **)(_r_modules_funcs_p + 200))
                       (0x1104,0,0x3e,0x12,*(code **)(_r_modules_funcs_p + 200));
    *puVar8 = 0x440e;
    iVar4 = _p_llm_env;
    puVar8[1] = uVar11;
    iVar4 = *(int *)(iVar4 + 8) + iVar3;
    *(undefined1 *)(puVar8 + 2) = *(undefined1 *)(iVar4 + 0x28);
    *(undefined1 *)((int)puVar8 + 5) = *(undefined1 *)(iVar4 + 0x41);
    memcpy(puVar8 + 3,(void *)(iVar4 + 4),6);
    *(undefined1 *)(puVar8 + 6) = 1;
    puVar8[7] = 6;
    *(undefined1 *)(puVar8 + 8) = 0;
    iVar4 = _r_ip_funcs_p;
_L862:
    (**(code **)(iVar4 + 0x8c))(puVar8,*(code **)(iVar4 + 0x8c));
  }
  else {
    if (param_1[1] == 8) {
      llm_sync_cancel_cc_act_id = 0xff;
      puVar8 = (undefined2 *)
               (**(code **)(_r_modules_funcs_p + 200))
                         (0x1104,0,0x3e,0x12,*(code **)(_r_modules_funcs_p + 200));
      *puVar8 = 0x3e0e;
      iVar4 = _p_llm_env;
      puVar8[1] = uVar11;
      iVar4 = *(int *)(iVar4 + 8) + iVar3;
      *(undefined1 *)(puVar8 + 2) = *(undefined1 *)(iVar4 + 0x28);
      *(undefined1 *)((int)puVar8 + 5) = *(undefined1 *)(iVar4 + 0x41);
      memcpy(puVar8 + 3,(void *)(iVar4 + 4),6);
      *(undefined1 *)(puVar8 + 6) = 1;
      puVar8[7] = 6;
      iVar4 = _r_ip_funcs_p;
      *(undefined1 *)(puVar8 + 8) = 0;
      goto _L862;
    }
    (**(code **)(_r_plf_funcs_p + 0xc))
              ((uint)bVar1,"llm_scan.c",0xbe4,*(code **)(_r_plf_funcs_p + 0xc));
  }
  (**(code **)(_r_modules_funcs_p + 0xd8))
            (*(int *)(*(int *)(_p_llm_env + 8) + iVar3) + -0xc,*(code **)(_r_modules_funcs_p + 0xd8)
            );
  *(undefined4 *)(*(int *)(_p_llm_env + 8) + iVar3) = 0;
_L849:
  *(undefined1 *)(*(int *)(_p_llm_env + 8) + iVar3 + 0x40) = 0;
  return 0;
}

