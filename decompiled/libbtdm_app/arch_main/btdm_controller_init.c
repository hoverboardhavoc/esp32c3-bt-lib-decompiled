/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> arch_main.o -> btdm_controller_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 btdm_controller_init(int *param_1)

{
  undefined1 uVar1;
  ushort uVar2;
  undefined2 uVar3;
  void *pvVar4;
  int *piVar5;
  char cVar6;
  byte bVar7;
  byte bVar8;
  byte bVar9;
  char *pcVar10;
  int iVar11;
  int iVar12;
  code *pcVar13;
  int *piVar14;
  undefined4 uVar15;
  uint uVar16;
  undefined1 uStack_34;
  byte bStack_33;
  
  uVar15 = 0xffffffff;
  if (_g_rw_init_sem != 0) goto _L336;
  _r_plf_funcs_p =
       (void *)(**(code **)(_r_osi_funcs_p + 0x78))(0x118,*(code **)(_r_osi_funcs_p + 0x78));
  if (((_r_plf_funcs_p == (void *)0x0) ||
      (_r_modules_funcs_p =
            (void *)(**(code **)(_r_osi_funcs_p + 0x78))(0x3d0,*(code **)(_r_osi_funcs_p + 0x78)),
      _r_modules_funcs_p == (void *)0x0)) ||
     (_r_ip_funcs_p =
           (void *)(**(code **)(_r_osi_funcs_p + 0x78))(0x9e4,*(code **)(_r_osi_funcs_p + 0x78)),
     _r_ip_funcs_p == (void *)0x0)) {
    if (0 < _g_bt_plf_log_level) {
      ets_printf("Funcs table create fails\n");
    }
    btdm_funcs_table_destroy();
    uVar15 = 0xfffffffe;
    goto _L336;
  }
  memcpy(_r_plf_funcs_p,&r_plf_funcs_ro,0x118);
  memcpy(_r_modules_funcs_p,&r_modules_funcs_ro,0x3d0);
  memcpy(_r_ip_funcs_p,&r_ip_funcs_ro,0x9e4);
  (**(code **)(_r_osi_funcs_p + 0xe4))(*(code **)(_r_osi_funcs_p + 0xe4));
  if ((*param_1 == 0x5a5aa5a5) && (param_1[1] == 0x2502230)) {
    if (((((uint)param_1[0xb] >> 0x10) - 1 & 0xff) < 2) &&
       ((((uint)param_1[0xb] >> 0x18) - 1 & 0xff) < 2)) {
      if (*(byte *)(param_1 + 0xc) < 2) {
        *(undefined1 *)(param_1 + 0xc) = 2;
      }
      if (*(ushort *)(param_1 + 0xd) < 0x101) {
        if (*(byte *)((int)param_1 + 0x1e) < 0x10) {
          (**(code **)((int)_r_plf_funcs_p + 0x44))(param_1,*(code **)((int)_r_plf_funcs_p + 0x44));
          sdk_config_set_mask(param_1[8]);
          sdk_config_set_opts_ext(param_1 + 8);
          sdk_config_overwrite_priv_opts();
          sdk_config_set_derived_opts();
          iVar11 = (**(code **)((int)_r_plf_funcs_p + 0xf0))(*(code **)((int)_r_plf_funcs_p + 0xf0))
          ;
          if (*(char *)(iVar11 + 0x1e) != '\0') {
            if (0 < _g_bt_plf_log_level) {
              ets_printf("Controller lib error, need flash lib\n");
            }
            uVar15 = 0xfffffff5;
            goto _L336;
          }
          if ((*(char *)((int)param_1 + 0x17) == '\0') &&
             (iVar11 = (**(code **)((int)_r_plf_funcs_p + 0xe8))
                                 (param_1[6],*(code **)((int)_r_plf_funcs_p + 0xe8)), iVar11 != 0))
          goto _L343;
          iVar11 = (**(code **)((int)_r_plf_funcs_p + 0x38))(*(code **)((int)_r_plf_funcs_p + 0x38))
          ;
          uStack_34 = *(undefined1 *)(iVar11 + 0xd);
          bStack_33 = DAT_0001302f;
          (**(code **)((int)_r_plf_funcs_p + 0x24))
                    (&uStack_34,*(code **)((int)_r_plf_funcs_p + 0x24));
          if (DAT_0001302e == '\0') {
            btdm_hli_get_null_funcs();
          }
          else {
            btdm_hli_get_funcs();
          }
          btdm_hli_funcs_register();
          _btdm_env_p = (int *)(**(code **)(_r_osi_funcs_p + 0x74))
                                         (0x28,*(code **)(_r_osi_funcs_p + 0x74));
          if (_btdm_env_p != (int *)0x0) {
            memset(_btdm_env_p,0,0x28);
            bVar7 = (**(code **)((int)_r_ip_funcs_p + 0x244))
                              (*(code **)((int)_r_ip_funcs_p + 0x244));
            bVar8 = (**(code **)((int)_r_ip_funcs_p + 0x4d0))
                              (*(code **)((int)_r_ip_funcs_p + 0x4d0));
            bVar9 = (**(code **)((int)_r_ip_funcs_p + 0xe4))(*(code **)((int)_r_ip_funcs_p + 0xe4));
            bVar9 = bVar7 & bVar8 & bVar9;
            if (DAT_0001302d != '\0') {
              bVar7 = (**(code **)((int)_r_plf_funcs_p + 0x4c))
                                (*(code **)((int)_r_plf_funcs_p + 0x4c));
              bVar9 = bVar7 & bVar9;
            }
            iVar11 = (**(code **)((int)_r_ip_funcs_p + 0x44))(*(code **)((int)_r_ip_funcs_p + 0x44))
            ;
            if ((iVar11 != 0) && (bVar9 != 0)) {
              iVar11 = (**(code **)((int)_r_plf_funcs_p + 0x38))
                                 (*(code **)((int)_r_plf_funcs_p + 0x38));
              bVar7 = *(byte *)(iVar11 + 0xd);
              iVar11 = (**(code **)((int)_r_plf_funcs_p + 0x38))
                                 (*(code **)((int)_r_plf_funcs_p + 0x38));
              bVar8 = *(byte *)(iVar11 + 0xd);
              uVar16 = (uint)DAT_0001302f;
              iVar11 = (**(code **)((int)_r_plf_funcs_p + 0x38))
                                 (*(code **)((int)_r_plf_funcs_p + 0x38));
              piVar14 = _btdm_env_p;
              iVar12 = 0;
              if (DAT_0001302e != '\0') {
                iVar12 = (uint)*(byte *)(iVar11 + 0xd) * 0x88 + uVar16 * 0xe0;
              }
              pcVar13 = *(code **)(_r_osi_funcs_p + 0x78);
              _btdm_env_p[1] =
                   ((bVar8 + 2) * 0xc + (uint)bVar7 * 0xe6 + 0x25b + iVar12 & 0xfffffffc) + 0xc;
              iVar11 = (*pcVar13)(pcVar13);
              pvVar4 = _r_plf_funcs_p;
              *piVar14 = iVar11;
              iVar11 = (**(code **)((int)pvVar4 + 0x38))(*(code **)((int)pvVar4 + 0x38));
              piVar14 = _btdm_env_p;
              uVar16 = 0;
              if (DAT_0001302e != '\0') {
                uVar16 = (uint)DAT_0001302f * 400;
                if ((uint)DAT_0001302f * 400 < 0x1800) {
                  uVar16 = 0x1800;
                }
              }
              pcVar13 = *(code **)(_r_osi_funcs_p + 0x78);
              _btdm_env_p[3] =
                   (((uint)*(byte *)(iVar11 + 0xd) * 0x104 + 0x8ef) * 2 + 0x675 + uVar16 &
                   0xfffffffc) + 0xc;
              iVar11 = (*pcVar13)(pcVar13);
              pvVar4 = _r_plf_funcs_p;
              piVar14[2] = iVar11;
              iVar11 = (**(code **)((int)pvVar4 + 0xf0))(*(code **)((int)pvVar4 + 0xf0));
              uVar2 = *(ushort *)(iVar11 + 8);
              iVar11 = (**(code **)((int)_r_plf_funcs_p + 0xf0))
                                 (*(code **)((int)_r_plf_funcs_p + 0xf0));
              piVar14 = _btdm_env_p;
              pcVar13 = *(code **)(_r_osi_funcs_p + 0x78);
              _btdm_env_p[5] =
                   (((uint)*(ushort *)(iVar11 + 6) * 0xc + (uint)uVar2 * 0x10 + 0x293 >> 2) + 3) * 4
              ;
              iVar11 = (*pcVar13)(pcVar13);
              cVar6 = DAT_0001302e;
              piVar14[4] = iVar11;
              piVar14 = _btdm_env_p;
              iVar11 = 0xc00;
              if (cVar6 == '\0') {
                iVar11 = 1;
              }
              pcVar13 = *(code **)(_r_osi_funcs_p + 0x78);
              _btdm_env_p[7] = (iVar11 + 3U & 0xfffffffc) + 0xc;
              iVar11 = (*pcVar13)(pcVar13);
              piVar5 = _btdm_env_p;
              piVar14[6] = iVar11;
              if ((((*piVar5 != 0) && (piVar5[2] != 0)) && (piVar5[4] != 0)) &&
                 ((piVar5[7] == 0 || (piVar5[6] != 0)))) {
                if (2 < _g_bt_plf_log_level) {
                  ets_printf("RWIP Heap alloc: ENV [%p %d], MSG [%p %d], NORET [%p %d], DB [%p %d]\n"
                             ,piVar5[1],piVar5[3],piVar5[5],piVar5[6]);
                }
                iVar11 = (**(code **)((int)_r_plf_funcs_p + 0x38))
                                   (*(code **)((int)_r_plf_funcs_p + 0x38));
                if ((*(char *)(iVar11 + 0x17) != '\0') &&
                   (iVar11 = (**(code **)((int)_r_plf_funcs_p + 0x38))
                                       (*(code **)((int)_r_plf_funcs_p + 0x38)),
                   piVar14 = _btdm_env_p, *(char *)(iVar11 + 0x17) == '\x01')) {
                  iVar11 = (**(code **)(_r_osi_funcs_p + 0x78))
                                     (0xc,*(code **)(_r_osi_funcs_p + 0x78));
                  piVar5 = _btdm_env_p;
                  piVar14[9] = iVar11;
                  if ((void *)piVar5[9] == (void *)0x0) goto _L357;
                  memset((void *)piVar5[9],0,0xc);
                }
                if (2 < _g_bt_plf_log_level) {
                  ets_printf("Uart ENV [%p], VHCI ENV [%p]\n",_btdm_env_p[8],_btdm_env_p[9]);
                }
                _g_rw_init_sem =
                     (**(code **)(_r_osi_funcs_p + 0x24))(1,0,*(code **)(_r_osi_funcs_p + 0x24));
                if (_g_rw_init_sem == 0) {
                  uVar15 = 0xfffffffb;
                }
                else {
                  _g_rw_schd_queue =
                       (**(code **)(_r_osi_funcs_p + 0x4c))(5,8,*(code **)(_r_osi_funcs_p + 0x4c));
                  if (_g_rw_schd_queue == 0) {
                    uVar15 = 0xfffffffa;
                  }
                  else {
                    pcVar13 = *(code **)(_r_osi_funcs_p + 0x24);
                    iVar11 = (**(code **)((int)_r_plf_funcs_p + 0xf8))
                                       (*(code **)((int)_r_plf_funcs_p + 0xf8));
                    uVar15 = (*pcVar13)(1,0);
                    pvVar4 = _r_plf_funcs_p;
                    *(undefined4 *)(iVar11 + 8) = uVar15;
                    iVar11 = (**(code **)((int)pvVar4 + 0xf8))(*(code **)((int)pvVar4 + 0xf8));
                    if (*(int *)(iVar11 + 8) == 0) {
                      uVar15 = 0xfffffff9;
                    }
                    else {
                      _g_waking_sleeping_sem =
                           (**(code **)(_r_osi_funcs_p + 0x24))(1,*(code **)(_r_osi_funcs_p + 0x24))
                      ;
                      if (_g_waking_sleeping_sem == 0) {
                        return 0xfffffff8;
                      }
                      pcVar13 = *(code **)(_r_osi_funcs_p + 100);
                      iVar11 = (**(code **)((int)_r_plf_funcs_p + 0x38))
                                         (*(code **)((int)_r_plf_funcs_p + 0x38));
                      uVar3 = *(undefined2 *)(iVar11 + 8);
                      iVar11 = (**(code **)((int)_r_plf_funcs_p + 0x38))
                                         (*(code **)((int)_r_plf_funcs_p + 0x38));
                      uVar1 = *(undefined1 *)(iVar11 + 10);
                      iVar11 = (**(code **)((int)_r_plf_funcs_p + 0x38))
                                         (*(code **)((int)_r_plf_funcs_p + 0x38));
                      iVar11 = (*pcVar13)(btdm_controller_task,"btController",uVar3,0,uVar1,
                                          &g_rw_controller_task_handle,*(undefined1 *)(iVar11 + 0xb)
                                         );
                      if (iVar11 == 1) {
                        (**(code **)((int)_r_plf_funcs_p + 0x28))
                                  (7,0,0,1,*(code **)((int)_r_plf_funcs_p + 0x28));
                        (**(code **)(_r_osi_funcs_p + 0x34))
                                  (_g_rw_init_sem,10000,*(code **)(_r_osi_funcs_p + 0x34));
                        return 0;
                      }
                      uVar15 = 0xfffffff7;
                    }
                  }
                }
                goto _L336;
              }
            }
          }
_L357:
          (**(code **)((int)_r_ip_funcs_p + 0x240))(*(code **)((int)_r_ip_funcs_p + 0x240));
          (**(code **)((int)_r_ip_funcs_p + 0x4cc))(*(code **)((int)_r_ip_funcs_p + 0x4cc));
          (**(code **)((int)_r_ip_funcs_p + 0xe0))(*(code **)((int)_r_ip_funcs_p + 0xe0));
          if (DAT_0001302d != '\0') {
            (**(code **)((int)_r_plf_funcs_p + 0x48))(*(code **)((int)_r_plf_funcs_p + 0x48));
          }
          (**(code **)((int)_r_ip_funcs_p + 0x40))(*(code **)((int)_r_ip_funcs_p + 0x40));
          if (*_btdm_env_p != 0) {
            (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
          }
          if (_btdm_env_p[2] != 0) {
            (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
          }
          if (_btdm_env_p[4] != 0) {
            (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
          }
          if (_btdm_env_p[6] != 0) {
            (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
          }
          piVar14 = _btdm_env_p;
          if (_btdm_env_p[9] != 0) {
            (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
            piVar14 = _btdm_env_p;
            _btdm_env_p[9] = 0;
          }
          uVar15 = 0xfffffffc;
          (**(code **)(_r_osi_funcs_p + 0x7c))(piVar14,*(code **)(_r_osi_funcs_p + 0x7c));
          _btdm_env_p = (int *)0x0;
          goto _L336;
        }
        if (0 < _g_bt_plf_log_level) {
          pcVar10 = "Default Tx Power Invalid: 0x%x\n";
          goto _L448;
        }
      }
      else if (0 < _g_bt_plf_log_level) {
        pcVar10 = "Invalid scan backoff upperlimitmax: 0x%x\n";
        goto _L448;
      }
    }
    else if (0 < _g_bt_plf_log_level) {
      pcVar10 = "Hardware Target Code Invalid: 0x%x\n";
_L448:
      ets_printf(pcVar10);
    }
  }
  else if (0 < _g_bt_plf_log_level) {
    ets_printf("Config struct mismatch: magic=%08x, ver=%08x\n",0x5a5aa5a5,0x2502230);
  }
_L343:
  uVar15 = 0xfffffffd;
_L336:
  btdm_controller_deinit_internal();
  return uVar15;
}

