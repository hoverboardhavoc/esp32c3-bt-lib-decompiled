/*
 * Last changed at upstream commit b8ef2c474d392a88ea7e6626f89acf1fa5f30e4a
 * https://github.com/espressif/esp32c3-bt-lib/commit/b8ef2c474d392a88ea7e6626f89acf1fa5f30e4a
 * Upstream date: 2024-09-06 16:51:15 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(c66a703)
 * Source: libbtdm_app -> llm_scan.o -> lld_per_adv_rx_end_ind_handler_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 lld_per_adv_rx_end_ind_handler_hack(byte *param_1)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  ushort *puVar7;
  undefined1 *puVar8;
  undefined2 *puVar9;
  undefined1 uVar10;
  int iVar11;
  ushort uVar12;
  
  bVar1 = *param_1;
  iVar4 = (uint)bVar1 * 0x44;
  iVar5 = *(int *)(_p_llm_env + 8) + iVar4;
  bVar2 = *(byte *)(iVar5 + 0x40);
  uVar12 = (ushort)bVar1;
  if (bVar2 != 0xe) {
    if ((bVar2 < 0xe) || (0x10 < bVar2)) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"llm_scan.c",0x84d,*(code **)(_r_plf_funcs_p + 8));
    }
    else {
      uVar10 = *(undefined1 *)(iVar5 + 0x41);
      (**(code **)(_r_ip_funcs_p + 0x6f4))(iVar5 + 0xc,*(code **)(_r_ip_funcs_p + 0x6f4));
      uVar6 = (**(code **)(_r_ip_funcs_p + 0x4c8))
                        (iVar5 + 4,uVar10,*(code **)(_r_ip_funcs_p + 0x4c8));
      if (uVar6 < 0xc) {
        iVar11 = uVar6 * 10 + _p_llm_env;
        if ((*(byte *)(iVar11 + 0x2d) & 4) != 0) {
          if (((int)(uint)*(ushort *)(iVar11 + 0x2a) >>
               (*(byte *)(*(int *)(_p_llm_env + 8) + iVar4 + 0x28) & 0x1f) & 1U) != 0) {
            (**(code **)(_r_ip_funcs_p + 600))(iVar5 + 4,uVar10,*(code **)(_r_ip_funcs_p + 600));
          }
        }
      }
      cVar3 = *(char *)(*(int *)(_p_llm_env + 8) + iVar4 + 0x40);
      if (cVar3 == '\x10') {
        (**(code **)(_r_ip_funcs_p + 0x4b8))(0x2046,0,*(code **)(_r_ip_funcs_p + 0x4b8));
      }
      else if (cVar3 == '\x0f') {
        puVar8 = (undefined1 *)
                 (**(code **)(_r_modules_funcs_p + 200))
                           (0x1104,0,0x3e,4,*(code **)(_r_modules_funcs_p + 200));
        *puVar8 = 0x10;
        iVar5 = _r_ip_funcs_p;
        *(ushort *)(puVar8 + 2) = uVar12;
        (**(code **)(iVar5 + 0x8c))(*(code **)(iVar5 + 0x8c));
      }
      if (*(short *)(*(int *)(_p_llm_env + 8) + iVar4 + 0x2a) != 0xff) {
        puVar7 = (ushort *)
                 (**(code **)(_r_modules_funcs_p + 200))(1,0,8,*(code **)(_r_modules_funcs_p + 200))
        ;
        iVar5 = _p_llm_env;
        *puVar7 = uVar12;
        uVar10 = 0x16;
        iVar5 = *(int *)(iVar5 + 8) + iVar4;
        if (*(char *)(iVar5 + 0x40) != '\x10') {
          uVar10 = 8;
        }
        *(undefined1 *)(puVar7 + 1) = uVar10;
        uVar10 = *(undefined1 *)(iVar5 + 0x29);
        *(undefined1 *)(puVar7 + 3) = 0;
        puVar7[2] = 0;
        *(undefined1 *)((int)puVar7 + 3) = uVar10;
        (**(code **)(_r_modules_funcs_p + 0xe0))(*(code **)(_r_modules_funcs_p + 0xe0));
      }
    }
    goto _L631;
  }
  if (param_1[1] == 0) {
    (**(code **)(_r_ip_funcs_p + 0x4b8))(0x2045,0,*(code **)(_r_ip_funcs_p + 0x4b8));
    puVar9 = (undefined2 *)
             (**(code **)(_r_modules_funcs_p + 200))
                       (0x1104,0,0x3e,0x12,*(code **)(_r_modules_funcs_p + 200));
    *puVar9 = 0x440e;
    iVar5 = _p_llm_env;
    puVar9[1] = uVar12;
    iVar5 = *(int *)(iVar5 + 8) + iVar4;
    *(undefined1 *)(puVar9 + 2) = *(undefined1 *)(iVar5 + 0x28);
    *(undefined1 *)((int)puVar9 + 5) = *(undefined1 *)(iVar5 + 0x41);
    memcpy(puVar9 + 3,(void *)(iVar5 + 4),6);
    *(undefined1 *)(puVar9 + 6) = 1;
    puVar9[7] = 6;
    *(undefined1 *)(puVar9 + 8) = 0;
    iVar5 = _r_ip_funcs_p;
_L644:
    (**(code **)(iVar5 + 0x8c))(puVar9,*(code **)(iVar5 + 0x8c));
  }
  else {
    if (param_1[1] == 8) {
      puVar9 = (undefined2 *)
               (**(code **)(_r_modules_funcs_p + 200))
                         (0x1104,0,0x3e,0x12,*(code **)(_r_modules_funcs_p + 200));
      *puVar9 = 0x3e0e;
      iVar5 = _p_llm_env;
      puVar9[1] = uVar12;
      iVar5 = *(int *)(iVar5 + 8) + iVar4;
      *(undefined1 *)(puVar9 + 2) = *(undefined1 *)(iVar5 + 0x28);
      *(undefined1 *)((int)puVar9 + 5) = *(undefined1 *)(iVar5 + 0x41);
      memcpy(puVar9 + 3,(void *)(iVar5 + 4),6);
      *(undefined1 *)(puVar9 + 6) = 1;
      puVar9[7] = 6;
      iVar5 = _r_ip_funcs_p;
      *(undefined1 *)(puVar9 + 8) = 0;
      goto _L644;
    }
    (**(code **)(_r_plf_funcs_p + 0xc))
              ((uint)bVar1,"llm_scan.c",0x842,*(code **)(_r_plf_funcs_p + 0xc));
  }
  (**(code **)(_r_modules_funcs_p + 0xd8))
            (*(int *)(*(int *)(_p_llm_env + 8) + iVar4) + -0xc,*(code **)(_r_modules_funcs_p + 0xd8)
            );
  *(undefined4 *)(*(int *)(_p_llm_env + 8) + iVar4) = 0;
_L631:
  *(undefined1 *)(iVar4 + *(int *)(_p_llm_env + 8) + 0x40) = 0;
  return 0;
}

