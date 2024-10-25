/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
  byte bVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  ushort *puVar6;
  undefined1 *puVar7;
  undefined2 *puVar8;
  int iVar9;
  undefined1 uVar10;
  int iVar11;
  ushort uVar12;
  
  iVar9 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar9 + 0x18) == '\0') {
    return 0;
  }
  bVar1 = *param_1;
  iVar9 = (uint)bVar1 * 0x44;
  iVar4 = *(int *)(_p_llm_env + 8) + iVar9;
  bVar2 = *(byte *)(iVar4 + 0x40);
  uVar12 = (ushort)bVar1;
  if (bVar2 != 0xe) {
    if ((bVar2 < 0xe) || (0x10 < bVar2)) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"llm_scan.c",0xb49,*(code **)(_r_plf_funcs_p + 8));
    }
    else {
      uVar10 = *(undefined1 *)(iVar4 + 0x41);
      (**(code **)(_r_ip_funcs_p + 0x6f4))(iVar4 + 0xc,*(code **)(_r_ip_funcs_p + 0x6f4));
      uVar5 = (**(code **)(_r_ip_funcs_p + 0x4c8))
                        (iVar4 + 4,uVar10,*(code **)(_r_ip_funcs_p + 0x4c8));
      if (((uVar5 < 0xc) && (iVar11 = uVar5 * 10 + _p_llm_env, (*(byte *)(iVar11 + 0x2d) & 4) != 0))
         && (((int)(uint)*(ushort *)(iVar11 + 0x2a) >>
              (*(byte *)(*(int *)(_p_llm_env + 8) + iVar9 + 0x28) & 0x1f) & 1U) != 0)) {
        (**(code **)(_r_ip_funcs_p + 600))(iVar4 + 4,uVar10,*(code **)(_r_ip_funcs_p + 600));
      }
      cVar3 = *(char *)(*(int *)(_p_llm_env + 8) + iVar9 + 0x40);
      if (cVar3 == '\x10') {
        (**(code **)(_r_ip_funcs_p + 0x4b8))(0x2046,0,*(code **)(_r_ip_funcs_p + 0x4b8));
      }
      else if (cVar3 == '\x0f') {
        puVar7 = (undefined1 *)
                 (**(code **)(_r_modules_funcs_p + 200))
                           (0x1104,0,0x3e,4,*(code **)(_r_modules_funcs_p + 200));
        *puVar7 = 0x10;
        iVar4 = _r_ip_funcs_p;
        *(ushort *)(puVar7 + 2) = uVar12;
        (**(code **)(iVar4 + 0x8c))(*(code **)(iVar4 + 0x8c));
      }
      if (*(short *)(*(int *)(_p_llm_env + 8) + iVar9 + 0x2a) != 0xff) {
        puVar6 = (ushort *)
                 (**(code **)(_r_modules_funcs_p + 200))(1,0,8,*(code **)(_r_modules_funcs_p + 200))
        ;
        iVar4 = _p_llm_env;
        *puVar6 = uVar12;
        uVar10 = 0x16;
        iVar4 = *(int *)(iVar4 + 8) + iVar9;
        if (*(char *)(iVar4 + 0x40) != '\x10') {
          uVar10 = 8;
        }
        *(undefined1 *)(puVar6 + 1) = uVar10;
        uVar10 = *(undefined1 *)(iVar4 + 0x29);
        *(undefined1 *)(puVar6 + 3) = 0;
        puVar6[2] = 0;
        *(undefined1 *)((int)puVar6 + 3) = uVar10;
        (**(code **)(_r_modules_funcs_p + 0xe0))(*(code **)(_r_modules_funcs_p + 0xe0));
      }
    }
    goto _L841;
  }
  if (param_1[1] == 0) {
    (**(code **)(_r_ip_funcs_p + 0x4b8))(0x2045,0,param_2,param_3,*(code **)(_r_ip_funcs_p + 0x4b8))
    ;
    puVar8 = (undefined2 *)
             (**(code **)(_r_modules_funcs_p + 200))
                       (0x1104,0,0x3e,0x12,*(code **)(_r_modules_funcs_p + 200));
    *puVar8 = 0x440e;
    iVar4 = _p_llm_env;
    puVar8[1] = uVar12;
    iVar4 = *(int *)(iVar4 + 8) + iVar9;
    *(undefined1 *)(puVar8 + 2) = *(undefined1 *)(iVar4 + 0x28);
    *(undefined1 *)((int)puVar8 + 5) = *(undefined1 *)(iVar4 + 0x41);
    memcpy(puVar8 + 3,(void *)(iVar4 + 4),6);
    *(undefined1 *)(puVar8 + 6) = 1;
    puVar8[7] = 6;
    *(undefined1 *)(puVar8 + 8) = 0;
    iVar4 = _r_ip_funcs_p;
_L854:
    (**(code **)(iVar4 + 0x8c))(puVar8,*(code **)(iVar4 + 0x8c));
  }
  else {
    if (param_1[1] == 8) {
      puVar8 = (undefined2 *)
               (**(code **)(_r_modules_funcs_p + 200))
                         (0x1104,0,0x3e,0x12,*(code **)(_r_modules_funcs_p + 200));
      *puVar8 = 0x3e0e;
      iVar4 = _p_llm_env;
      puVar8[1] = uVar12;
      iVar4 = *(int *)(iVar4 + 8) + iVar9;
      *(undefined1 *)(puVar8 + 2) = *(undefined1 *)(iVar4 + 0x28);
      *(undefined1 *)((int)puVar8 + 5) = *(undefined1 *)(iVar4 + 0x41);
      memcpy(puVar8 + 3,(void *)(iVar4 + 4),6);
      *(undefined1 *)(puVar8 + 6) = 1;
      puVar8[7] = 6;
      iVar4 = _r_ip_funcs_p;
      *(undefined1 *)(puVar8 + 8) = 0;
      goto _L854;
    }
    (**(code **)(_r_plf_funcs_p + 0xc))
              ((uint)bVar1,"llm_scan.c",0xb3e,*(code **)(_r_plf_funcs_p + 0xc));
  }
  (**(code **)(_r_modules_funcs_p + 0xd8))
            (*(int *)(*(int *)(_p_llm_env + 8) + iVar9) + -0xc,*(code **)(_r_modules_funcs_p + 0xd8)
            );
  *(undefined4 *)(*(int *)(_p_llm_env + 8) + iVar9) = 0;
_L841:
  *(undefined1 *)(iVar9 + *(int *)(_p_llm_env + 8) + 0x40) = 0;
  return 0;
}

